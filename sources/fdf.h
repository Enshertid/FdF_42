/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:13:41 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 17:22:00 by ymanilow         ###   ########.fr       */
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
# define FALL 33
# define I 34
# define O 31
# define Y_LEFT 86
# define Y_RIGHT 88
# define X_DOWN 84
# define X_UP 91
# define Z_DOWN 83
# define Z_UP 92
# define C 8
# define K 40
# define G 4
# define SHIFT 257
# define RED_F 0xFF0000
# define BLUE_F 0x3a75c4
# define WHITE_F 0xFFFFFF
# define GREEN_F 0x33FF00
# define PURPLE_F 0xFF00FF
# define YELLOW_F 0xFFFF00
# define TURQUOISE_F 0x33FFFF
# define ORANGE_F 0xFF9900
# define HEIGHT 1400
# define WIDTH 2570
# define ANGLE 0.174533
# define ANGLE_MOUSE 0.0872665

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

typedef struct		s_angle
{
	double			angle_x;
	double			angle_y;
	double			angle_z;
	double			sin_x;
	double			cos_x;
	double			sin_y;
	double			cos_y;
	double			sin_z;
	double			cos_z;
	double			x_x;
	double			y_x;
	double			z_x;
	double			x_y;
	double			y_y;
	double			z_y;
	double			x_z;
	double			y_z;
	double			z_z;
}					t_angle;

typedef struct		s_color
{
	double			i_r;
	double			i_g;
	double			i_b;
	int				color_s;
	int				color_e;
	int				custom_color;
}					t_color;

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	double			r;
	double			g;
	double			b;
}					t_dot;

typedef struct		s_mouse
{
	int				x;
	int				y;
	t_bool			left_but;
	t_bool			right_but;
}					t_mouse;

typedef struct		s_modes
{
	t_bool			iso;
	t_bool			grad;
	t_bool			shift;
	t_bool			flag_color;
	t_bool			flag_first;
}					t_modes;


typedef struct		s_base
{
	int				z_p;
	int				size;
	int				z_min;
	int				start_x;
	int				start_y;
}					t_base;

typedef struct		s_pointers
{
	t_image			img;
	t_dot			dot_s;
	t_dot			dot_e;
	t_base			base;
	t_mtrx			mtrx;
	t_matr			*matr;
	t_angle			angle;
	t_color			color;
	t_mouse			mouse;
	t_modes			mod;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_pointers;

void				ft_parsing(t_pointers *point, int ac, char **str);
void				ft_list_add(t_matr *head, t_matr *new);
t_matr				*ft_list_create(int ln, char *line, t_pointers *point);

void				ft_draw_matrix_img(t_pointers *point);
void				ft_draw_matrix_img_iso(t_pointers *p);
void				ft_iso(int *x, int *y, int z, t_pointers *point);

void				ft_print_line_img(t_pointers *p, t_dot dot_s, int color);
void				ft_print_line_img_grad(t_pointers *p, t_dot dot_s, int color_start, int color_end);

void				ft_set_dot(t_pointers *point);
void				ft_set_custom_color(t_pointers *point);

void				ft_set_angles(t_pointers *point);
void				ft_change_angle(t_pointers *point, int key);
void				ft_check_angle(t_pointers *point, int *x, int *y, int *z);
void				ft_change_all_angles(t_pointers *point, int *x, int *y, int *z);

void				ft_angle_movement(t_pointers *point, int x, int y);
void				ft_movement(t_pointers *point, int x, int y);

void				ft_check_key(t_pointers *point, int key);
int					ft_key_hook_img(int key, t_pointers *point);
int					ft_key_release(int key, t_pointers *point);
int					ft_mouse_press(int button, int x, int y, t_pointers *point);
int					ft_mouse_release(int button, int x, int y, t_pointers *point);
int					ft_mouse_movement(int x, int y, t_pointers *point);


#endif
