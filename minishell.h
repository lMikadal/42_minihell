/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:21:53 by pmikada           #+#    #+#             */
/*   Updated: 2022/12/19 15:40:23 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <term.h>

# define PATH "PATH="
# define USER "USER="
# define EXIT "exit"

typedef struct s_data
{
	char	**path;
	char	*user;
}	t_data;

void	ft_lexer(char *s);
char	**ft_split(char const *s, char c);
int		ft_strlen(char const *s);
char	*ft_strcpy_add(char const *s1, char const *s2);
char	**ft_split_cmd(char *s);
void	ft_free_all(t_data *data);
void	ft_free_2d(char **s);

#endif
