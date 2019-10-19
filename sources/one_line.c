/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:11:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/18 21:55:30 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

int				m_n(int num)
{
	return (num > 0 ? num : -num);
}

void			ft_print_line(t_pointers *p, t_point dot)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	lnx = ft_mod_num(dot.x2 - dot.x1);
	lny = ft_mod_num(dot.y2 - dot.y1);
	ln = ft_max(lnx, lny) + 1;
	d = m_n(dot.y2 - dot.y1) <= m_n(dot.x2 - dot.x1) ? -lnx : -lny;
	while (ln--)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, dot.x1, dot.y1, dot.color);
		if (lny <= lnx)
			dot.x1 += dot.x2 - dot.x1 >= 0 ? 1 : -1;
		else
			dot.y1 += dot.y2 - dot.y1 >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot.y1 += dot.y2 - dot.y1 >= 0 ? 1 : -1;
			else
				dot.x1 += dot.x2 - dot.x1 >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
	}
}
