/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:38 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/02 12:17:58 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_dot(t_pointers *point)
{
	int			i;
	int			j;

	point->dot_s.x = 10;
	point->dot_s.y = 10;
	point->base.iso = 0;
	point->base.size = 2;
	point->base.color = BLUE_F;
	point->base.start_x = 10;
	point->base.start_y = 10;
	point->base.angle_x = 0;
	point->base.angle_y = 0;
	point->base.angle_z = 0;
	i = -1;
	j = -1;
	while (++i < point->mtrx.ln_y)
		while (++j < point->mtrx.ln_x)
			point->base.z_min = ft_mod_num(point->base.z_min) <= ft_mod_num(point->mtrx.array[i][j]) ?
					point->mtrx.array[i][j] : point->base.z_min;
	point->dot_s.z = point->base.z_min;
}

void	ft_change_x(t_pointers *point, int *y, int *z)
{
	int start_y;
	int start_z;

	start_y = *y;
	start_z = *z;
	*y = start_z * sin(point->base.angle_x) + (start_y * cos(point->base.angle_x));
	*z = start_z * cos(point->base.angle_x) - start_y * sin(point->base.angle_x);
}

void	ft_change_y(t_pointers *point, int *x, int *z)
{
	int start_x;
	int start_z;

	start_x = *x;
	start_z = *z;
	*x = start_x * cos(point->base.angle_y) - start_z * sin(point->base.angle_y);
	*z = start_x * sin(point->base.angle_y) + start_z * cos(point->base.angle_y);
}

void	ft_change_z(t_pointers *point, int *x, int *y)
{
	int start_x;
	int start_y;

	start_x = *x;
	start_y = *y;
	*x = start_x * cos(point->base.angle_z) + start_y * sin(point->base.angle_z);
	*y = start_y * cos(point->base.angle_z) - start_x * sin(point->base.angle_z);
}

void	ft_change_angle(t_pointers *point, int key)
{
	int			d;

	d = 1;
	if (key == X_DOWN || key == Z_DOWN || key == Y_LEFT)
		d = -1;
	if (key == X_UP || key == X_DOWN)
		point->base.angle_x += 0.174533 * d;
	else if (key == Z_DOWN || key == Z_UP)
		point->base.angle_z += 0.174533 * d;
	else if (key == Y_RIGHT || key == Y_LEFT)
		point->base.angle_y += 0.174533 * d;
	if (point->base.angle_x == 1 || point->base.angle_x == -1)
		point->base.angle_x = 0;
	if (point->base.angle_y == 1 || point->base.angle_y == -1)
		point->base.angle_y = 0;
	if (point->base.angle_z == 1 || point->base.angle_z == -1)
		point->base.angle_z = 0;
}

void	ft_change_all_angles(t_pointers *point, int *x, int *y, int *z)
{
	int s_x;
	int s_y;
	int s_z;
	double sin_x = sin (point->base.angle_x);
	double cos_x = cos (point->base.angle_x);
	double sin_y = sin (point->base.angle_y);
	double cos_y = cos (point->base.angle_y);
	double sin_z = sin (point->base.angle_z);
	double cos_z = cos (point->base.angle_z);

	s_x = *x;
	s_y = *y;
	s_z = *z;
	*x = s_x * cos_y * cos_z + s_y * sin_x * sin_y * cos_z + s_y * cos_x * sin_z -
			s_z * sin_y * cos_x * cos_z + s_z * sin_x + s_z * sin_z;
	*y = -s_x * sin_z * cos_y - s_y * sin_x * sin_y * sin_z + s_y * cos_x * cos_z +
			s_z * sin_y * cos_x * sin_z + sin_x * cos_z * s_z;
	*z = s_x * sin_y + s_y * cos_y * sin_x + s_z * cos_y * cos_x;
}

void	ft_check_angle(t_pointers *point, int *x, int *y, int *z)
{
	if (*z != point->base.z_min)
		*z += point->base.z_p;
//	if (point->dot1.angle_x || point->dot1.angle_y || point->dot1.angle_z)
//		ft_change_all_angles(point, x, y, z);
	if (point->base.angle_x != 0)
		ft_change_x(point, y, z);
	if (point->base.angle_y != 0)
		ft_change_y(point, x, z);
	if (point->base.angle_z != 0)
		ft_change_z(point, x, y);
}

void	ft_copy_of_array(t_mtrx *dst, t_mtrx *src, t_pointers *point)
{
	int		i;

	i = -1;
	while (++i < point->mtrx.ln_y)
		ft_memcpy(dst->array[i], src->array[i], sizeof(int) * point->mtrx.ln_x);
}

void	ft_check_key(t_pointers *point, int key)
{
	int d;
	
	if (key == O)
		point->base.iso = 0;
	if (key == I)
		point->base.iso = 1;
	if (key == SPACE)
		ft_set_dot(point);
	if (key == PLUS || key == LEFT || key == UP)
		d = -1;
	else
		d = 1;
	if (key == PLUS)
	{
		point->base.start_x += 1;
		point->base.start_y += 1;
		point->base.size -= 1;
	}
	if (key == MINUS)
	{
		point->base.start_x -= 1;
		point->base.start_y -= 1;
		point->base.size += 1;
	}
	if ((key == LEFT || key == RIGHT) && point->base.iso == 1)
	{
		point->base.start_x += 10 * d;
		point->base.start_y -= 10 * d;
	}
	else if ((key == LEFT || key == RIGHT) && point->base.iso == 0)
		point->base.start_x += 10 * d;
	if ((key == DOWN || key == UP) && point->base.iso == 1)
	{
		point->base.start_x += 10 * d;
		point->base.start_y += 10 * d;
	}
	if (key == C)
	{
		point->base.start_x = 750;
		point->base.start_y = 750;
	}
	else if ((key == DOWN || key == UP) && point->base.iso == 0)
		point->base.start_y += 20 * d;
	if (key == ESC)
		exit(0);
	if (key == RISE)
		point->base.z_p += 2;
	if (key == UNRISE)
		point->base.z_p -= 2;
	if (key == Y_LEFT || key == Y_RIGHT || key == X_DOWN || key == X_UP ||
		key == Z_DOWN || key == Z_UP)
		ft_change_angle(point, key);
}

int		ft_key_hook_img(int key, void *param)
{
	t_pointers *point;
	
	point = param;
	ft_check_key(point, key);
	ft_memset(point->img.char_ptr, 0, point->img.ln_size * 2000);
	mlx_clear_window(point->mlx_ptr, point->win_ptr);
	if (point->base.iso == 0)
		ft_draw_matrix_img(point);
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
	point.win_ptr = mlx_new_window(point.mlx_ptr, 2000, 2000, "HELLO . BOY");
	point.img.img_ptr = mlx_new_image(point.mlx_ptr,2000, 2000);
	point.img.char_ptr = mlx_get_data_addr(point.img.img_ptr, &point.img.bpp, &point.img.ln_size,
			&point.img.endian);
	mlx_hook(point.win_ptr, 2, 0, ft_key_hook_img, &point);
	mlx_clear_window(point.mlx_ptr, point.win_ptr);
	mlx_loop(point.mlx_ptr);
	mlx_destroy_image(point.mlx_ptr, point.win_ptr);
	return (0);
}
