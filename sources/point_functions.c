/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:17 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/04 03:10:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_set_color(t_pointers *point)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (point->color.flag_color == 1)
	{
		while (++i < point->mtrx.ln_y)
		{
			while (++j < point->mtrx.ln_x)
				point->mtrx.color[i][j] = point->mtrx.color[i][j] ? point->mtrx.color[i][j]
						: WHITE_F;
			j = -1;
		}
	}
	i = -1;
	j = -1;
	while (++i < point->mtrx.ln_y)
	{
		while (++j < point->mtrx.ln_x)
			point->base.z_min = ft_mod_num(point->base.z_min) <
					ft_mod_num(point->mtrx.array[i][j]) ?
						point->base.z_min : point->mtrx.array[i][j];
		j = -1;
	}
}

void				ft_set_dot(t_pointers *point)
	{
	if (point->base.flag_first == 1 && point->color.flag_color == 1)
	{
		point->base.flag_first = 0;
		ft_set_color(point);
	}
	if (point->mtrx.ln_x > 100 || point->mtrx.ln_y > 100)
		point->base.size = 2;
	else
		point->base.size = 50;
	if (point->base.flag_first == 1)
		point->base.iso = 1;
	point->base.start_x = WIDTH / 2;
	point->base.start_y = HEIGHT / 2;


	point->dot_s.z = point->base.z_min;
	point->dot_e.z = point->base.z_min;
}