/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:31:52 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 18:59:22 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_set_angles(t_pointers *point)
{
	point->angle.sin_x = sin (point->angle.angle_x);
	point->angle.cos_x = cos (point->angle.angle_x);
	point->angle.sin_y = sin (point->angle.angle_y);
	point->angle.cos_y = cos (point->angle.angle_y);
	point->angle.sin_z = sin (point->angle.angle_z);
	point->angle.cos_z = cos (point->angle.angle_z);
	point->angle.x_x = point->angle.cos_y * point->angle.cos_z;
	point->angle.y_x = -point->angle.sin_z * point->angle.cos_x +
			point->angle.cos_z * point->angle.sin_y * point->angle.sin_x;
	point->angle.z_x = point->angle.sin_z * point->angle.sin_x +
			point->angle.cos_z * point->angle.sin_y * point->angle.cos_x;
	point->angle.x_y = point->angle.sin_z * point->angle.cos_y;
	point->angle.y_y = point->angle.cos_z * point->angle.cos_x +
			point->angle.sin_z * point->angle.sin_y * point->angle.sin_x;
	point->angle.z_y = -point->angle.sin_x * point->angle.cos_z +
			point->angle.sin_z * point->angle.sin_y * point->angle.cos_x;
	point->angle.x_z = -point->angle.sin_y;
	point->angle.y_z = point->angle.cos_y * point->angle.sin_x;
	point->angle.z_z = point->angle.cos_x * point->angle.cos_y;
}

void				ft_change_all_angles(t_pointers *point, int *x, int *y, int *z)
{
	int s_x;
	int s_y;
	int s_z;


	s_x = *x;
	s_y = *y;
	s_z = *z;
	*x = s_x * point->angle.x_x + s_y * point->angle.y_x + s_z * point->angle.z_x;
	*y = s_x * point->angle.x_y + s_y * point->angle.y_y + s_z * point->angle.z_y;
	*z = s_x * point->angle.x_z + s_y * point->angle.y_z + s_z * point->angle.z_z;
}

void				ft_change_angle(t_pointers *point, int key)
{
	int			d;

	d = 1;
	if (key == X_DOWN || key == Z_DOWN || key == Y_LEFT)
		d = -1;
	if (key == X_UP || key == X_DOWN)
		point->angle.angle_x += 0.174533 * d;
	else if (key == Z_DOWN || key == Z_UP)
		point->angle.angle_z += 0.174533 * d;
	else if (key == Y_RIGHT || key == Y_LEFT)
		point->angle.angle_y += 0.174533 * d;
	if (point->angle.angle_x == 1 || point->angle.angle_x == -1)
		point->angle.angle_x = 0;
	if (point->angle.angle_y == 1 || point->angle.angle_y == -1)
		point->angle.angle_y = 0;
	if (point->angle.angle_z == 1 || point->angle.angle_z == -1)
		point->angle.angle_z = 0;
	ft_set_angles(point);
}

void				ft_check_angle(t_pointers *point, int *x, int *y, int *z)
{
	if (*z != point->base.z_min)
		*z += point->base.z_p;
	if (point->angle.angle_x || point->angle.angle_y || point->angle.angle_z)
		ft_change_all_angles(point, x, y, z);
//	if (point->angle.angle_x != 0)
//		ft_change_x(point, y, z);
//	if (point->angle.angle_y != 0)
//		ft_change_y(point, x, z);
//	if (point->angle.angle_z != 0)
//		ft_change_z(point, x, y);
}