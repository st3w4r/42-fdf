# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2014/12/01 19:36:12 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRC =	main.c \
		parse_arg.c \
		get_next_line.c \
		fdf_draw.c \
		fdf_cal_matrice.c \
		fdf_matrice.c \
		fdf_error.c \
		fdf_hook.c \
		fdf_helper.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I libft/includes/ -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11 -g


.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
