/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:11:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/16 15:11:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_print_obt_angle(t_pointers *point, int x, int y, int sign_a, int sign_b, int end_x, int end_y)
{
	int f;
	int a;
	int b;

	f = 0;
	a = ft_mod_num(end_y - y);
	b = ft_mod_num(end_x - x);
	while (x != end_x && y != end_y)
	{
		f += a;
		if (f > 0)
		{
			f -= b;
			y += sign_a;
		}
		x += sign_b;
		mlx_pixel_put(point->mlx_ptr, point->win_ptr, x, y, 0xABCFFF);
	}
}

void		ft_print_sharp_angle(t_pointers *point, int x, int y, int sign_a, int sign_b, int end_x, int end_y)
{
	int f;
	int a;
	int b;

	f = 0;
	a = ft_mod_num(end_y - y);
	b = ft_mod_num(end_x - x);
	while (x != end_x && y != end_y)
	{
		f += b;
		if (f > 0)
		{
			f -= a;
			x += sign_b;
		}
		y += sign_a;
		mlx_pixel_put(point->mlx_ptr, point->win_ptr, x, y, 0xBCAFFF);
	}
}

void		ft_print_inclined_line(int start_x, int start_y, int end_x, int end_y, t_pointers *point)
{
	int		a;
	int		b;
	int		f;
	int sign_a;
	int sign_b;

	f = 0;
	a = end_y - start_y;
	b = end_x - start_x;
	sign_a = a < 0 ? -1 : 1;
	sign_b = b < 0 ? -1 : 1;
	a = ft_mod_num(a);
	b = ft_mod_num(b);
	mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xABCFFF);
	if (a < b)
		ft_print_obt_angle(point, start_x, start_y, sign_a, sign_b, end_x, end_y);
	else
		ft_print_sharp_angle(point, start_x, start_y, sign_a, sign_b, end_x, end_y);
}

void		ft_print_straight_line(int start_x, int start_y, int end_x, int end_y, t_pointers *point)
{
	if (end_x == start_x)
	{
		while (start_y != end_y)
		{
			mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xBCAFFF);
			start_y = start_y < end_y ? start_y + 1 : start_y - 1;
		}
	}
	else
	{
		while (start_x != end_x)
		{
			mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xBCAFFF);
			start_x = start_x < end_x ? start_x + 1 : start_x - 1;
		}
	}
}