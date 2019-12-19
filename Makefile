# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 10:58:26 by ymanilow          #+#    #+#              #
#    Updated: 2019/12/19 18:38:50 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

DIR_S = sources

DIR_O = obj

DIR_H = includes/

LIB = ./libft/

LIBMLX =  -Imlx/ -L ./mlx/ -l mlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -I$(DIR_H) -I$(LIB)includes_l -I$(LIB)includes_p

SRCS_C = fdf.c	parsing.c	work_with_angle_consistent.c				\
	point_functions.c	drawing_lines.c	drawing_matrix.c				\
	treatment_of_signals.c	work_with_angles.c	point_list_functions.c	\
	keyboard.c mouse.c	draw_matrix_on_iso.c	draw_line_with_grad.c	\
	menu.c																\

SRCS_O = $(addprefix $(DIR_O)/,$(SRCS_C:.c=.o))

all: $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(SRCS_O)
	@make -C ./mlx/
	@make -C $(LIB)
	$(CC) $(FLAGS) $(LIB)libft.a $(LIBMLX) $(SRCS_O) -o $(NAME)

clean:
	@make clean -C $(LIB)
	@rm -Rf $(SRCS_O)
	@rm -Rf $(DIR_O)

fclean: clean
	@make fclean -C $(LIB)
	@make clean -C ./mlx/
	@rm -Rf $(NAME)
	
re: fclean all
