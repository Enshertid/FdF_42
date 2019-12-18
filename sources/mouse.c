/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:28:24 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/18 12:10:33 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_movement(t_pointers *point, int x, int y)
{
	if (point->mouse.x < x)
		point->base.start_x--;
	else
		point->base.start_x++;
	if (point->mouse.y < y)
		point->base.start_y--;
	else
		point->base.start_y++;
	point->base.start_x = x - point->mtrx.ln_x * point->base.size / 2;
	point->base.start_y = y - point->mtrx.ln_y * point->base.size / 2;
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (!point->mod.iso)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	if (point->mod.tab)
		ft_output_of_menu(point);
	point->mouse.x = x;
	point->mouse.y = y;
}

void				ft_angle_movement(t_pointers *point, int x, int y)
{
	if (point->mouse.x < x && point->mod.shift)
		point->angle.angle_y += ANGLE_MOUSE;
	else if (point->mouse.x > x && point->mod.shift)
		point->angle.angle_y -= ANGLE_MOUSE;
	if (point->mouse.y < y && !point->mod.shift)
		point->angle.angle_x += ANGLE_MOUSE;
	else if (point->mouse.y > y && !point->mod.shift)
		point->angle.angle_x -= ANGLE_MOUSE;
	ft_set_angles(point);
	ft_change_angle(point,0);
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (!point->mod.iso)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	if (point->mod.tab)
		ft_output_of_menu(point);
	point->mouse.x = x;
	point->mouse.y = y;
}
