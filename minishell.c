/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:47 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/19 13:26:15 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexer(char *s)
{
	char	**cmd;

	cmd = ft_split_cmd(s);
	int	i = -1;
	while (cmd[++i])
		printf("cmd[%d] %s\n", i, cmd[i]);
	ft_free_2d(cmd);
}
