# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:53:13 by jmartel           #+#    #+#              #
#    Updated: 2019/04/26 15:03:38 by jmartel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libps.a

SRCS		=	./libps_swap.c ./libps_push.c
SRCS		+=	./libps_rotate.c ./libps_reverse_rotate.c
SRCS		+=	./libps_t_push.c ./libps_t_pile.c
SRCS		+=	./libps_tools.c

OBJ			= $(SRCS:%.c=%.o)

HEADERS		= ./libps.h

INCLUDES	= -I. -I../ -I../libft

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra $(INCLUDES) -g3

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ) && echo "\033[32mSuccessfully compiled $(NAME) \033[0m"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ) && echo "\033[32mSuccessfully cleaned $(NAME) objects files \033[0m"

fclean: clean
	@rm -f $(NAME) && echo "\033[32mSuccessfully cleaned $(NAME) \033[0m"

re: fclean all
