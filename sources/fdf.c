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

void	ft_set_dot(t_pointers *point)
{
	point->dot.x1 = 10;
	point->dot.y1 = 10;
	point->dot.start_x = 10;
	point->dot.start_y = 10;
	point->dot.size = 20;
	point->dot.color = 0xFFFFFF;
	point->dot.z = 0;
	point->dot.iso = 0;
}

void	ft_change_angle()

void	ft_check_key(t_pointers *point, int key)
{
	int d;
	
	if (key == O)
		point->dot.iso = 0;
	if (key == I)
		point->dot.iso = 1;
	if (key == SPACE)
		ft_set_dot(point);
	if (key == PLUS || key == LEFT || key == UP)
		d = -1;
	else
		d = 1;
	if (key == PLUS)
	{
		point->dot.start_x += 5;
		point->dot.start_y += 5;
		point->dot.size -= 5;
	}
	if (key == MINUS)
	{
		point->dot.start_x -= 5;
		point->dot.start_y -= 5;
		point->dot.size += 5;
	}
	if ((key == LEFT || key == RIGHT) && point->dot.iso == 1)
	{
		point->dot.start_x += 10 * d;
		point->dot.start_y -= 10 * d;
	}
	else if ((key == LEFT || key == RIGHT) && point->dot.iso == 0)
		point->dot.start_x += 10 * d;
	if ((key == DOWN || key == UP) && point->dot.iso == 1)
	{
		point->dot.start_x += 10 * d;
		point->dot.start_y += 10 * d;
	}
	else if ((key == DOWN || key == UP) && point->dot.iso == 0)
		point->dot.start_y += 10 * d;
	if (key == ESC)
		exit(0);
	if (key == RISE)
		point->dot.z += 5;
	if (key == UNRISE)
		point->dot.z -= 5;
	ft_memcpy(&point->dot1, &point->dot, sizeof(point->dot));
}

int		ft_key_hook_img(int key, void *param)
{
	t_pointers *point;
	
	point = param;
	ft_check_key(point, key);
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * 1000);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->dot.iso == 0)
		ft_draw_matrix_img(point, point->dot.iso);
	else
		ft_draw_matrix_img_iso(point);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img.img_ptr, 0, 0);
	ft_printf("%d\n",key);
	return(key);
}

int		main(int ac, char **av)
{
	t_pointers		point;
	
	ft_memset(&point, 0, sizeof(t_pointers));
	ft_parsing(&point, ac, av);
	ft_set_dot(&point);
	point.mlx_ptr = mlx_init();
	point.win_ptr = mlx_new_window(point.mlx_ptr, 1500, 1000, "HELLO . BOY");
	point.img.img_ptr = mlx_new_image(point.mlx_ptr,1500, 1000);
	point.img.char_ptr = mlx_get_data_addr(point.img.img_ptr, &point.img.bpp, &point.img.ln_size,
										   &point.img.endian);
	mlx_hook(point.win_ptr, 2, 0, ft_key_hook_img, &point);
	mlx_clear_window(point.mlx_ptr, point.win_ptr);
	mlx_loop(point.mlx_ptr);
	mlx_destroy_image(point.mlx_ptr, point.win_ptr);
	return (0);
}
