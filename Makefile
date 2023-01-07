# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:19:29 by pmikada           #+#    #+#              #
#    Updated: 2022/12/19 13:25:33 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c utils.c utils2.c utils_free.c

MAIN = main.c

CC = cc

FLAGS = -Wall -Wextra -Werror

FLAG_L = -lreadline

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FLAG_L) -o $(NAME) $(MAIN) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
