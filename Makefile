# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2019/12/01 14:42:27 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_C = ./sources/fdf.c ./sources/one_line.c ./sources/parsing.c\
./sources/list_functions.c\

SRCS_O = $(SRCS_C:.c=.o)

LIBMLX = -L ./mlx/ -l mlx -framework OpenGL -framework AppKit

LIB = ./ft_printf/libftprintf.a

all: $(NAME)

%.o: sources/%.c
	@gcc -Wall -Wextra -Werror -c $(SRCS_C)

$(NAME): $(SRCS_O)
	@make -C ./mlx/
	@make -C ./ft_printf/
	gcc -Wall -Wextra -Werror -Isources/ -Imlx/ $(LIBMLX) $(LIB) $(SRCS_O) -o $(NAME)

clean:
	make clean -C ./ft_printf
	rm -Rf $(SRCS_O)

fclean: clean
	make fclean -C ./ft_printf/ 
	make clean -C ./mlx/
	rm -Rf ./fdf
	
re: fclean all

g: 
	@make -C ./mlx/
	@make -C ./ft_printf/
	@gcc -Wall -Wextra -Werror -g -Isources/ -Imlx/ $(LIBMLX) $(LIB) $(SRCS_O) -o $(NAME)

c:
	@make clean -C ./ft_printf/
	@rm -Rf $(SRCS_O)
	clear
