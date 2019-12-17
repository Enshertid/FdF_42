/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_angle_consistent.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:32:32 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 15:55:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_iso(int *x, int *y, int z, t_pointers *point)
{
	int start_x;
	int start_y;

	start_x = *x;
	start_y = *y;
	if (z != point->base.z_min)
		z += point->base.z_p;
	*x = (start_x - start_y) * 0.86632463631;
	*y = (-z + (start_x + start_y) * 0.50000019433);
}

void				ft_change_x(t_pointers *point, int *y, int *z)
{
	int start_y;
	int start_z;

	start_y = *y;
	start_z = *z;
	*y = start_z * sin(point->angle.angle_x) +
			(start_y * cos(point->angle.angle_x));
	*z = start_z * cos(point->angle.angle_x) -
			start_y * sin(point->angle.angle_x);
}

void				ft_change_y(t_pointers *point, int *x, int *z)
{
	int start_x;
	int start_z;

	start_x = *x;
	start_z = *z;
	*x = start_x * cos(point->angle.angle_y) +
			start_z * sin(point->angle.angle_y);
	*z = -start_x * sin(point->angle.angle_y) +
			start_z * cos(point->angle.angle_y);
}

void				ft_change_z(t_pointers *point, int *x, int *y)
{
	int start_x;
	int start_y;

	start_x = *x;
	start_y = *y;
	*x = start_x * cos(point->angle.angle_z) -
			start_y * sin(point->angle.angle_z);
	*y = start_y * cos(point->angle.angle_z) +
			start_x * sin(point->angle.angle_z);
}