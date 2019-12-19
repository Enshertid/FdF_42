/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:45 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/19 18:37:20 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_output_of_menu_text(t_pointers *point)
{
	mlx_string_put(point->mlx_ptr, point->win_ptr, 100, 20, WHITE_F,
			"MENU OF FDF");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 10, 50, WHITE_F,
			"USAGE OF BUTTONS :");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 80, WHITE_F,
			"'G' - switch gradient");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 110, WHITE_F,
			"'I' - switch ISO mod");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 140, WHITE_F,
			"'K' - switch color mod");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 170,
			WHITE_F, "'C' - to set the figure in center");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 200, WHITE_F,
			"'TAB' - to set menu off/on");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 230, WHITE_F,
			"'SPACE' - to set values to zero");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 35, 260, WHITE_F,
			"Mouse wheel for zoom");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 10, 300, WHITE_F,
			"CURRENT VALUES :");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30, 420, WHITE_F,
			"Size of cell : ");
}

void				ft_output_of_menu_sizeofcall(t_pointers *point)
{
	char			*size;

	if (point->base.size < 0)
		point->base.size = 0;
	size = ft_itoa(point->base.size);
	if (point->base.size > 0)
		mlx_string_put(point->mlx_ptr, point->win_ptr,
				200, 420, WHITE_F, size);
	else
	{
		mlx_string_put(point->mlx_ptr, point->win_ptr,
				200, 420, WHITE_F, "0");
		mlx_string_put(point->mlx_ptr, point->win_ptr,
				point->base.start_x + point->base.size * point->mtrx.ln_x,
				point->base.start_y + point->base.size * point->mtrx.ln_y,
				WHITE_F, "FIGURE IS TOO FAR");
	}
	free(size);
}

void				ft_output_of_current_values_of_angles(t_pointers *point)
{
	char			*x;
	char			*y;
	char			*z;

	x = ft_itoa(point->angle.anx);
	y = ft_itoa(point->angle.any);
	z = ft_itoa(point->angle.anz);
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30,
			330, WHITE_F, "ANGLE X : ");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 150, 330, WHITE_F, x);
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30,
			360, WHITE_F, "ANGLE Y : ");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 150, 360, WHITE_F, y);
	mlx_string_put(point->mlx_ptr, point->win_ptr, 30,
			390, WHITE_F, "ANGLE Z : ");
	mlx_string_put(point->mlx_ptr, point->win_ptr, 150, 390, WHITE_F, z);
	free(x);
	free(y);
	free(z);
}

void				ft_output_of_menu(t_pointers *point)
{
	point->dot_s.x = MENU_Y;
	point->dot_s.y = 0;
	point->dot_e.x = MENU_Y;
	point->dot_e.y = HEIGHT;
	ft_print_line_img(point, point->dot_s, WHITE_F);
	point->dot_s.x = MENU_Y + 1;
	point->dot_s.y = 0;
	point->dot_e.x = MENU_Y + 1;
	point->dot_e.y = HEIGHT;
	ft_print_line_img(point, point->dot_s, WHITE_F);
	mlx_put_image_to_window(point->mlx_ptr, point->win_ptr,
			point->img.img_ptr, 0, 0);
	ft_output_of_current_values_of_angles(point);
	ft_output_of_menu_sizeofcall(point);
	ft_output_of_menu_text(point);
}
