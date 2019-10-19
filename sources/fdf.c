/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:38 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/19 18:55:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void		ft_draw_matrix(t_pointers *point)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	while (j <= point->ln_y)
	{
		while (i <= point->dot->ln)
		{
			point->dot_p.x1 = i * point->dot_p.size + point->dot_p.size_start_x;
			point->dot_p.y1 = j * point->dot_p.size + point->dot_p.size_start_y;
			point->dot_p.y2 = j * point->dot_p.size + point->dot_p.size_start_y;
			if (i != point->dot->ln)
			{
				point->dot_p.x2 = (i + 1) * point->dot_p.size + point->dot_p.size_start_x;
				ft_print_line(point, point->dot_p);
			}
			point->dot_p.x2 = i * point->dot_p.size + point->dot_p.size_start_x;
			if (j != point->ln_y)
			{
				point->dot_p.y2 = (j + 1) * point->dot_p.size + point->dot_p.size_start_y;
				ft_print_line(point, point->dot_p);
			}
			i++;
		}
		i = 1;
		j++;
	}
}

int			ft_key_hook(int key, void *param)
{
	t_pointers		*point;
	int				d;

	if (key == 27 || key == 123 || key == 126)
		d = -1;
	else
		d = 1;
	ft_printf("%d" ,key);
	if (key == 53)
		exit(0);
	point = param;
	if (key == 27)
	{
		point->dot_p.size_start_x += 10;
		point->dot_p.size_start_y += 10;
		point->dot_p.size -= 10;
	}
	if (key == 24)
	{
		point->dot_p.size_start_x -= 10;
		point->dot_p.size_start_y -= 10;
		point->dot_p.size += 10;
	}
	if (key == 123 || key == 124)
		point->dot_p.size_start_x += 50 * d;
	if (key == 125 || key == 126)
		point->dot_p.size_start_y += 50 * d;
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	ft_draw_matrix(point);
}

int		main(int ac, char **av)
{
	t_pointers		point;
	t_dot			*tmp;

	ft_memset(&point, 0, sizeof(t_pointers));
	point.mlx_ptr = mlx_init();
	point.win_ptr = mlx_new_window(point.mlx_ptr, 2500, 1500, "HELLO . BOY");
	ft_parsing(&point, ac, av);
	point.dot_p.x1 = 100;
	point.dot_p.y1 = 100;
	point.dot_p.size_start_x = 0;
	point.dot_p.size_start_y = 0;
	point.dot_p.size = 100;
	point.dot_p.color = 0xFFFFFF;
	point.ln_y = 1;
	tmp = point.dot;
	while (tmp->next)
	{
		tmp = tmp->next;
		point.ln_y++;
	}
	mlx_hook(point.win_ptr, 3, 0, ft_key_hook, &point);

	mlx_loop(point.mlx_ptr);
	return (0);
}
