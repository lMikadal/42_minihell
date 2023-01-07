/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:37 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/19 13:25:59 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_word(char *str, char *word)
{
	int	i;
	int	len_w;

	i = -1;
	len_w = ft_strlen(word);
	while (++i < len_w)
	{
		if (str[i] != word[i])
			return (0);
	}
	return (1);
}

static void	ft_set_path(t_data *data, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_check_word(env[i], PATH))
			data->path = ft_split(&env[i][5], ':');
	}
}

static void	ft_set_user(t_data *data, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_check_word(env[i], USER))
			data->user = ft_strcpy_add(&env[i][5], "> ");
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*cmd;

	(void)ac;
	(void)av;
	ft_set_path(&data, env);
	ft_set_user(&data, env);
	while (1)
	{
		cmd = readline(data.user);
		printf("complie %s\n", cmd);
		if (ft_check_word(cmd, EXIT))
		{
			ft_free_all(&data);
			exit (0);
		}
	}
	ft_free_all(&data);
	return (0);
}
