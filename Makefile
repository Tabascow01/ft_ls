# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 04:47:56 by mchemakh          #+#    #+#              #
#    Updated: 2017/06/20 13:58:28 by mchemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -fsanitize=address -O1 -fno-optimize-sibling-calls

SRCS_NAME = main.c init.c parser.c clear.c error.c option.c verif.c core.c ft_recursive.c ft_long.c ft_all.c ft_reverse.c ft_time.c ft_get.c storage.c

SRCS_PATH = srcs/

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = objs/

LIB = libft/
LIB_NAME = -lft
LIB_PATH = -L./libft/

INC_PATH = -I includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
#	@make -C $(LIB)
#	@make -C $(LIB_MLX)
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) -g -o $(NAME) $(LIB_PATH) $(LIB_NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_PATH) -g -o $@ -c $?

clean:
	@rm -rf $(OBJ_PATH)
#	@make clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
#	@make clean -C $(LIB_MLX)
#	@make fclean -C $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re
