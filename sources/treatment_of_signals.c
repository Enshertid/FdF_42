/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_of_signals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:33:04 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/03 23:05:08 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_key_hook_img(int key, void *param)
{
	t_pointers *point;

	point = param;
	ft_check_key(point, key);
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->base.iso == 0)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	ft_printf("%d\n",key);
	return(key);
}


int					ft_mouse_press(int button, int x, int y, void *param)
{
	t_pointers *point;

	point = param;
	if (button == 4)
		point->base.size += 2;
	else if (button == 5)
		point->base.size -= 2;
	if (button == 1)
	{
		point->base.start_x = x - point->mtrx.ln_x * point->base.size / 2;
		point->base.start_y = y - point->mtrx.ln_y * point->base.size / 2;
		point->left = 1;
	}
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->base.iso == 0)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	return(button);
}

int					ft_mouse_release(int button, int x, int y, void *param)
{
	t_pointers *point;

	point = param;
	if (point->left == 0)
	{
		point->base.start_x = x;
		point->base.start_y = y;
	}
	if (button == 1)
		point->left = 0;
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->base.iso == 0)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	return(button);
}

int					ft_mouse_movement(int x, int y, void *param)
{
	t_pointers *point;

	point = param;
	point->x = x;
	point->y = y;
	if (point->left)
	{
		if (point->x < x)
			point->base.start_x--;
		else
			point->base.start_x++;
		if (point->y < y)
			point->base.start_y--;
		else
			point->base.start_y++;
		point->base.start_x = x - point->mtrx.ln_x * point->base.size / 2;
		point->base.start_y = y - point->mtrx.ln_y * point->base.size / 2;
	}
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->base.iso == 0)
		ft_draw_matrix_img(point);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	return (1);
}