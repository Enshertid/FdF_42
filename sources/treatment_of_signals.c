/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_of_signals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:33:04 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/18 12:43:46 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_key_hook_img(int key, t_pointers *point)
{
	ft_check_key(point, key);
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (!point->mod.iso && point->base.size > 0)
		ft_draw_matrix_img(point);
	else if (point->base.size > 0)
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	if (point->mod.tab)
		ft_output_of_menu(point);
	ft_printf("%d\n",key);
	return(key);
}

int					ft_key_release(int key, t_pointers *point)
{
	if (key == SHIFT)
		point->mod.shift = FALSE;
	return (0);
}

int					ft_mouse_press(int button, int x, int y, t_pointers *point)
{
	if (button == 1)
		point->mouse.left_but = TRUE;
	else if (button == 2)
		point->mouse.right_but = TRUE;
	else
	{
		if (button == 4)
			point->base.size++;
		else if (button == 5)
			point->base.size--;
		ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
		mlx_clear_window(point->mlx_ptr, point->win_ptr);
		if (!point->mod.iso &&  point->base.size > 0)
			ft_draw_matrix_img(point);
		else if (point->base.size > 0)
			ft_draw_matrix_img_iso(point);
		mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	}
	if (point->mod.tab)
		ft_output_of_menu(point);
	point->mouse.x = x;
	point->mouse.y = y;
	return(button);
}

int					ft_mouse_release(int button, int x, int y, t_pointers *point)
{
	if (button == 1)
		point->mouse.left_but = FALSE;
	else if (button == 2)
		point->mouse.right_but = FALSE;
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * HEIGHT);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (!point->mod.iso && point->base.size > 0)
		ft_draw_matrix_img(point);
	else if (point->base.size > 0)
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	if (point->mod.tab)
		ft_output_of_menu(point);
	point->mouse.x = x;
	point->mouse.y = y;
	return (button);
}

int					ft_mouse_movement(int x, int y, t_pointers *point)
{
	if (point->mouse.left_but)
		ft_movement(point, x, y);
	else if (point->mouse.right_but)
		ft_angle_movement(point, x, y);
	return (1);
}