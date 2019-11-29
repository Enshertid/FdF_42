/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:13:41 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/19 16:40:58 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SPACE 49
# define PLUS 27
# define MINUS 24
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ESC 53
# define RISE 30
# define UNRISE 33
# define I 34
# define O 31
# define Y_LEFT 86
# define Y_RIGHT 88
# define X_DOWN 85
# define X_UP 91
# define Z_DOWN 83
# define Z_UP 92

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>

typedef struct		s_matr
{
	int				*array;
	int				ln;
	struct s_matr	*prev;
	struct s_matr	*next;
}					t_matr;

typedef struct		s_mtrx
{
	int	**array;
	int ln_x;
	int	ln_y;
}					t_mtrx;

typedef struct		s_dot1
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				start_y;
	int				start_x;
	int				z;
	int				size;
	int				color;
	int				iso;
}					t_dot1;

typedef struct		s_dot
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				start_y;
	int				start_x;
	int				z;
	int				size;
	int				color;
	int				iso;
}					t_dot;

typedef struct		s_image
{
	void			*img_ptr;
	char			*char_ptr;
	int				bpp;
	int				ln_size;
	int				endian;
}					t_image;

typedef struct		s_pointers
{
	t_image			img;
	t_dot			dot;
	t_dot1			dot1;
	t_mtrx			mtrx;
	t_matr			*matr;
	void			*mlx_ptr;
	void			*win_ptr;
	double 			angle;
}					t_pointers;

void				ft_parsing(t_pointers *point, int ac, char **str);
void				ft_list_add(t_matr *head, t_matr *new);
void				ft_draw_matrix_img_iso(t_pointers *point);
t_matr				*ft_list_create(int ln, char *line);

void				ft_print_line_pp(t_pointers *point, t_dot dot, int color);
void				ft_draw_matrix_img(t_pointers *point, int iso);
void				ft_print_line_img(t_pointers *p, t_dot dot, int color);
void				ft_iso(int *x, int *y, int z, t_pointers *point);

#endif
