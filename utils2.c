/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:09:29 by pmikada           #+#    #+#             */
/*   Updated: 2023/01/07 20:09:30 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_loop_word(char const *s, int i, char const c)
{
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (i);
}

static int	ft_count_word2(char const *s)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			if (i == 0)
				word++;
			i = ft_loop_word(s, i, s[i]);
		}
		if (s[i] != '|' && (i == 0 || s[i - 1] == '|'))
			word++;
	}
	return (word);
}

static char	*ft_loc_str2(char const *s, int start, int end)
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

char	**ft_split_cmd(char *s)
{
	char	**re;
	int		i;
	int		word;
	int		start;
	int		len_s;

	re = (char **)malloc((ft_count_word2(s) + 1) * sizeof(char *));
	if (re == NULL)
		return (0);
	i = -1;
	word = 0;
	len_s = ft_strlen(s);
	while (++i <= len_s)
	{
		if (s[i] == 34 || s[i] == 39)
			i = ft_loop_word(s, i, s[i]);
		if (s[i] != '|' && (i == 0 || s[i - 1] == '|'))
			start = i;
		if (i != 0 && s[i - 1] != '|' && (s[i] == '|' || s[i] == '\0'))
			re[word++] = ft_loc_str2(s, start, i);
	}
	re[word] = 0;
	return (re);
}
