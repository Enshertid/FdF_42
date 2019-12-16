/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:34:30 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 19:47:40 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_draw_matrix_img_iso(t_pointers *p)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++j < p->mtrx.ln_y)
	{
		while (++i < p->mtrx.ln_x)
		{
			p->dot_s.x = i * p->base.size + p->base.start_x;
			p->dot_s.y = j * p->base.size + p->base.start_y;
			ft_iso(&p->dot_s.x, &p->dot_s.y, p->mtrx.array[j][i], p);
			p->dot_e.y = j * p->base.size + p->base.start_y;
			if (i != p->mtrx.ln_x - 1)
			{
				p->dot_e.x = (i + 1) * p->base.size + p->base.start_x;
				ft_iso(&p->dot_e.x, &p->dot_e.y, p->mtrx.array[j][i + 1], p);
				if (p->mtrx.array[j][i] != p->base.z_min || p->mtrx.array[j][i + 1] != p->base.z_min)
					ft_print_line_img_grad(p,p->dot_s, p->mtrx.color[j][i], p->mtrx.color[j][i + 1]);
				else
					ft_print_line_img(p, p->dot_s, p->mtrx.color[j][i]);
			}
			p->dot_e.x = i * p->base.size + p->base.start_x;
			if (j != p->mtrx.ln_y - 1)
			{
				p->dot_e.y = (j + 1) * p->base.size + p->base.start_y;
				ft_iso(&p->dot_e.x, &p->dot_e.y, p->mtrx.array[j + 1][i], p);
				if (p->mtrx.array[j][i] != p->base.z_min || p->mtrx.array[j + 1][i] != p->base.z_min)
					ft_print_line_img_grad(p, p->dot_s,p->mtrx.color[j][i], p->mtrx.color[j+ 1][i]);
				else
					ft_print_line_img(p, p->dot_s, p->mtrx.color[j][i]);
			}
		}
		i = -1;
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
			p->dot_s.x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
			p->dot_s.y = j * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
			p->dot_s.z = p->mtrx.array[j][i];
			ft_check_angle(p, &p->dot_s.x, &p->dot_s.y, &p->dot_s.z);
			p->dot_s.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
			p->dot_s.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
			if (i != p->mtrx.ln_x - 1)
			{
				p->dot_e.y = j * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
				p->dot_e.x = (i + 1) * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.z = p->mtrx.array[j][i + 1];
				ft_check_angle(p, &p->dot_e.x, &p->dot_e.y, &p->dot_e.z);
				p->dot_e.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
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
			if (j != p->mtrx.ln_y - 1)
			{
				p->dot_e.x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.y = (j + 1) * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
				p->dot_e.z = p->mtrx.array[j + 1][i];
				ft_check_angle(p, &p->dot_e.x, &p->dot_e.y, &p->dot_e.z);
				p->dot_e.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
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
		}
		i = -1;
	}
}