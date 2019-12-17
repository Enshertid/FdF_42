/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:34:30 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 19:37:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_set_coord(t_pointers *p, t_dot *dot, int j, int i)
{
	dot->x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
	dot->y = j * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
	dot->z = p->mtrx.array[j][i];
	ft_check_angle(p, &dot->x, &dot->y, &dot->z);
	dot->x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
	dot->y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
}

void				ft_draw_line_top(t_pointers *p, int j, int i)
{
	if (p->mod.grad)
		ft_print_line_img_grad(p, p->dot_s, p->mtrx.color[j][i], p->mtrx.color[j][i + 1]);
	else
	{
		if (p->mtrx.color[j][i + 1] == p->color.custom_color)
			ft_print_line_img(p, p->dot_s, p->mtrx.color[j][i + 1]);
		else
			ft_print_line_img(p, p->dot_s, p->mtrx.color[j][i]);
	}
}

void				ft_draw_line_bot(t_pointers *p, int j, int i)
{
	if (p->mod.grad)
		ft_print_line_img_grad(p, p->dot_s, p->mtrx.color[j][i], p->mtrx.color[j + 1][i]);
	else
	{
		if (p->mtrx.color[j + 1][i] == p->color.custom_color)
			ft_print_line_img(p, p->dot_s, p->mtrx.color[j + 1][i]);
		else
			ft_print_line_img(p, p->dot_s, p->mtrx.color[j][i]);
	}
}

void				ft_draw_matrix_img(t_pointers *p)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++j < p->mtrx.ln_y)
	{
		while (++i < p->mtrx.ln_x)
		{
			ft_set_coord(p, &p->dot_s, j, i);
			if (i != p->mtrx.ln_x - 1)
			{
				ft_set_coord(p, &p->dot_e, j, i + 1);
				ft_draw_line_top(p, j, i);
			}
			if (j != p->mtrx.ln_y - 1)
			{
				ft_set_coord(p, &p->dot_e, j + 1, i);
				ft_draw_line_bot(p, j, i);
			}
		}
		i = -1;
	}
}