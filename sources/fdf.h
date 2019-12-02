/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:13:41 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/02 13:11:44 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define UP 126
# define ESC 53
# define RISE 30
# define DOWN 125
# define PLUS 27
# define LEFT 123
# define SPACE 49
# define MINUS 24
# define RIGHT 124
# define UNRISE 33
# define I 34
# define O 31
# define Y_LEFT 86
# define Y_RIGHT 88
# define X_DOWN 84
# define X_UP 91
# define Z_DOWN 83
# define Z_UP 92
# define C 8
# define BLUE_F 0x3a75c4
# define PURPLE_F 0xFF00FF
# define WHITE_F 0xFFFFFF
# define RED_F 0xe32636

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>

typedef struct		s_image
{
	int				bpp;
	int				endian;
	int				ln_size;
	void			*img_ptr;
	char			*char_ptr;
}					t_image;

typedef struct		s_matr
{
	int				ln;
	int				*array;
	int				*color;
	struct s_matr	*next;
}					t_matr;

typedef struct		s_mtrx
{
	int	ln_x;
	int	ln_y;
	int	**array;
	int	**color;
}					t_mtrx;


typedef struct		t_base
{
	int				z_p;
	int				iso;
	int				size;
	int				color;
	int				z_min;
	int				start_x;
	int				start_y;
	double			angle_x;
	double			angle_y;
	double			angle_z;
}					t_base;

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef struct		s_pointers
{
	t_image			img;
	t_dot			dot_s;
	t_dot			dot_e;
	t_base			base;
	t_mtrx			mtrx;
	t_matr			*matr;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_pointers;

void				ft_parsing(t_pointers *point, int ac, char **str);
void				ft_list_add(t_matr *head, t_matr *new);
void				ft_draw_matrix_img_iso(t_pointers *point);
t_matr				*ft_list_create(int ln, char *line);

void				ft_draw_matrix_img(t_pointers *point);
void				ft_print_line_img(t_pointers *p, t_dot dot_s, t_dot dot_e, int color);
void				ft_iso(int *x, int *y, int z, t_pointers *point);

void				ft_check_angle(t_pointers *point, int *x, int *y, int *z);
void				ft_print_line_img_grad(t_pointers *p, t_dot dot_s, t_dot dot_e, double color_start, double color_end);
int					ft_is_hex(char c);

#endif
