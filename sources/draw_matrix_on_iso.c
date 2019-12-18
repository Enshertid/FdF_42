/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_on_iso.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:03:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 22:12:34 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_set_coor_iso(t_pointers *p, t_dot *dot, int j, int i)
{
	dot->x = i * p->base.size;
	dot->y = j * p->base.size;
	dot->z = p->mtrx.array[j][i];
	ft_iso(&dot->x, &dot->y, dot->z, p);
	dot->x += p->base.start_x;
	dot->y += p->base.start_y;
}

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
			ft_set_coor_iso(p, &p->dot_s,j ,i);
			if (i != p->mtrx.ln_x - 1)
			{
				ft_set_coor_iso(p, &p->dot_e, j ,i + 1);
				ft_draw_line_top(p, j, i);
			}
			if (j != p->mtrx.ln_y - 1)
			{
				ft_set_coor_iso(p, &p->dot_e, j + 1 ,i);
				ft_draw_line_bot(p, j, i);
			}
		}
		i = -1;
	}
}

