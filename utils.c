/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:11:20 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/19 16:11:34 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
	}
	return (word);
}

static char	*ft_loc_str(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		word;
	int		start;
	int		len_s;

	re = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (re == NULL)
		return (0);
	i = -1;
	word = 0;
	len_s = ft_strlen(s);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (i != 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			re[word++] = ft_loc_str(s, start, i);
	}
	re[word] = 0;
	return (re);
}

int	ft_strlen(char const *s)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (s[++i])
		len += 1;
	return (len);
}

char	*ft_strcpy_add(char const *s1, char const *s2)
{
	char	*re;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	re = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (re == NULL)
		return (0);
	j = 0;
	i = -1;
	while (++i < len_s1)
		re[j++] = s1[i];
	i = -1;
	while (++i < len_s2)
		re[j++] = s2[i];
	return (re);
}
