/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:38 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 19:36:25 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Left button — 1

Right button — 2

Third (Middle) button — 3

Scroll Up — 4

Scroll Down — 5

Scroll Left — 6

Scroll Right — 7
 */
int		main(int ac, char **av)
{
	t_pointers		point;
	
	ft_memset(&point, 0, sizeof(t_pointers));
	ft_parsing(&point, ac, av);
	ft_set_dot(&point);
	point.mlx_ptr = mlx_init();
	point.win_ptr = mlx_new_window(point.mlx_ptr, WIDTH, HEIGHT, "HELLO . BOY");
	point.img.img_ptr = mlx_new_image(point.mlx_ptr, WIDTH, HEIGHT);
	point.img.char_ptr = mlx_get_data_addr(point.img.img_ptr, &point.img.bpp, &point.img.ln_size,
			&point.img.endian);
	mlx_hook(point.win_ptr, 2, 0, ft_key_hook_img, &point);
	mlx_hook(point.win_ptr, 3, 0, ft_key_release, &point);
	mlx_hook(point.win_ptr, 4, 0, ft_mouse_press, &point);
	mlx_hook(point.win_ptr, 6, 0, ft_mouse_movement, &point);
	mlx_hook(point.win_ptr, 5, 0, ft_mouse_release, &point);
	mlx_clear_window(point.mlx_ptr, point.win_ptr);
	mlx_loop(point.mlx_ptr);
	mlx_destroy_image(point.mlx_ptr, point.win_ptr);
	return (0);
}
