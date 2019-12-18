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