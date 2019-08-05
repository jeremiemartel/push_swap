# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 11:38:17 by jmartel           #+#    #+#              #
#    Updated: 2019/08/05 20:29:50 by jmartel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	name

# SPEED = -j8

SRC_DIR	=	srcs
OBJ_DIR	=	objs
BIN_DIR	=	.
INC_DIR	=	includes

PS_DIR	=	ps
CHK_DIR	=	checker

PS_NAME	=	push_swap
CHK_NAME=	checker

LIBFT_DIR	=	./libft
LIBPS_DIR	=	./libps

LIBFT		=	$(LIBFT_DIR)/libft.a
LIBPS		=	$(LIBPS_DIR)/libps.a
LIBS		=	$(LIBFT) $(LIBPS)

INCLUDES	=	$(INC_DIR)
INC			=	-I $(INC_DIR) -I $(LIBFT_DIR) -I $(LIBPS_DIR)

PS_SRC_NO_PREF	=	push_swap.c ps_parsing.c ps_tools.c \
					ps_sort_select.c ps_sort_wtf.c ps_sort_dichotomie.c

CHK_SRC_NO_PREF	=	checker.c \
					ck_parsing.c ck_options.c \
					ck_is_valid_op.c \
					ck_tools.c

PS_SRC	=	$(addprefix $(SRC_DIR)/$(PS_DIR)/, $(PS_SRC_NO_PREF))
CHK_SRC	=	$(addprefix $(SRC_DIR)/$(CHK_DIR)/, $(CHK_SRC_NO_PREF))

PS_OBJ	=	$(addprefix $(OBJ_DIR)/$(PS_DIR)/, $(PS_SRC_NO_PREF:%.c=%.o))
CHK_OBJ	=	$(addprefix $(OBJ_DIR)/$(CHK_DIR)/, $(CHK_SRC_NO_PREF:%.c=%.o))


CC		=	gcc
CFLAGS	=	$(INC) -Wall -Werror -Wextra

ifeq ($(DEBUG), 1)
	CFLAGS	+= -g3 -fsanitize=address
endif

.PHONY: all, clean, fclean, re

################################# BASIC RULES #################################

all:
	@make $(NAME) $(SPEED)

$(NAME):
	@make -C $(LIBFT_DIR) $(SPEED)
	@make -C $(LIBPS_DIR) $(SPEED)
	@make $(CHK_NAME) $(SPEED)
	@make $(PS_NAME) $(SPEED)

debug:
	@make all DEBUG=1

$(CHK_NAME): $(LIBFT) $(LIBPS) $(CHK_OBJ) 
	@$(CC) $(CFLAGS) $(CHK_OBJ) $(LIBS) -o $@ && echo "\033[32mSuccessfully compiled $@ \033[0m"

$(PS_NAME): $(LIBFT) $(LIBPS) $(PS_OBJ)
	@$(CC) $(CFLAGS) $(PS_OBJ) $(LIBS) -o $@ && echo "\033[32mSuccessfully compiled $@ \033[0m"

$(OBJ_DIR)/$(CHK_DIR)/%.o : $(SRC_DIR)/$(CHK_DIR)/%.c $(INC_DIR)/checker.h
	@mkdir -p $(OBJ_DIR)/$(CHK_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(PS_DIR)/%.o : $(SRC_DIR)/$(PS_DIR)/%.c  $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)/$(PS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: lib_clean
	@rm -f $(OBJS) && echo "\033[32mSuccessfully cleaned objects files \033[0m"
	@rm -rf $(OBJ_DIR)

fclean: lib_fclean
	@rm -f $(OBJS) && echo "\033[32mSuccessfully cleaned objects files \033[0m"
	@rm -rf $(OBJ_DIR)
	@rm -f $(CHK_NAME) && echo "\033[32mSuccessfully cleaned $(CHK_NAME) \033[0m"
	@rm -f $(PS_NAME) && echo "\033[32mSuccessfully cleaned $(PS_NAME) \033[0m"

re: fclean all

rere_clean:
	@rm -f $(OBJS) && echo "\033[32mSuccessfully cleaned objects files \033[0m"
	@rm -rf $(OBJ_DIR)
	@rm -f $(CHK_NAME) && echo "\033[32mSuccessfully cleaned $(CHK_NAME) \033[0m"
	@rm -f $(PS_NAME) && echo "\033[32mSuccessfully cleaned $(PS_NAME) \033[0m"

rere: rere_clean $(NAME)

################################# LIBFT RULES #################################

$(LIBFT):
	@make -C ./libft all
$(LIBPS):
	@make -C ./libps all

lib_clean:
	@make -C ./libft clean
	@make -C ./libps clean

lib_fclean:
	@make -C ./libft fclean
	@make -C ./libps fclean

lib_re:
	@make -C ./libft re
	@make -C ./libps re
