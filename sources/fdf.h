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

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct		s_dot
{
	int				*array;
	int				ln;
	struct s_dot	*prev;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				size_start_y;
	int				size_start_x;
	int				size;
	int				color
}					t_point;

typedef struct		s_pointers
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_dot			*dot;
	t_point			dot_p;
	int				ln_y;
}					t_pointers;

void				ft_parsing(t_pointers *point, int ac, char **str);
void				ft_list_add(t_dot *head, t_dot *new);
t_dot				*ft_list_create(int ln, char *line);

void				ft_print_line(t_pointers *point, t_point dot_p);
void				ft_print_inclined_line(int start_x, int start_y,
					int end_x, int end_y, t_pointers *point);

#endif
