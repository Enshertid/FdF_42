# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2019/12/03 23:35:17 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_C = ./sources/fdf.c ./sources/parsing.c ./sources/work_with_angle_consistent.c\
./sources/point_functions.c ./sources/drawing_lines.c ./sources/drawing_matrix.c\
./sources/treatment_of_signals.c ./sources/work_with_angles.c sources/point_list_functions.c\
./sources/keyboard.c\

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
