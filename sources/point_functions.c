/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:17 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 19:36:25 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_set_custom_color(t_pointers *point)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < point->mtrx.ln_y)
	{
		while (++j < point->mtrx.ln_x)
			point->mtrx.color[i][j] = point->base.z_min ==
								point->mtrx.array[i][j] ?
								WHITE_F : point->color.custom_color;
		j = -1;
	}
}

void				ft_set_color(t_pointers *point)
{
	int i;
	int j;

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
	i = -1;
	j = -1;
	if (point->mod.flag_color)
		while (++i < point->mtrx.ln_y)
		{
			while (++j < point->mtrx.ln_x)
				point->mtrx.color[i][j] = point->mtrx.color[i][j] ? point->mtrx.color[i][j]
																  : WHITE_F;
			j = -1;
		}
	else
		ft_set_custom_color(point);
}

void				ft_set_dot(t_pointers *point)
{
	if (point->mod.flag_first)
	{
		point->mod.flag_first = FALSE;
		point->color.custom_color = WHITE_F;
		ft_set_color(point);
	}
	if (point->mtrx.ln_x > 100 || point->mtrx.ln_y > 100)
		point->base.size = 2;
	else
		point->base.size = 50;
	if (point->mod.flag_first)
		point->mod.iso = TRUE;
	point->base.start_x = WIDTH / 3;
	point->base.start_y = HEIGHT / 3;
	point->angle.angle_x = 0;
	point->angle.angle_y = 0;
	point->angle.angle_z = 0;
	point->dot_s.z = point->base.z_min;
	point->dot_e.z = point->base.z_min;
}