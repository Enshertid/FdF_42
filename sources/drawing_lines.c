/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:31:04 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 22:51:23 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_cycle_of_print(t_pointers *p, t_dot dot,
										int ln, int color)
{
	int		lnx;
	int		lny;
	int		d;

	lnx = ft_mod_num(p->dot_e.x - dot.x);
	lny = ft_mod_num(p->dot_e.y - dot.y);
	d = lny<= lnx ? -lnx : -lny;
	while (ln--)
	{
		if (lny <= lnx)
			dot.x += p->dot_e.x - dot.x >= 0 ? 1 : -1;
		else
			dot.y += p->dot_e.y - dot.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot.y += p->dot_e.y - dot.y >= 0 ? 1 : -1;
			else
				dot.x += p->dot_e.x - dot.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dot.x >= WIDTH || dot.x < p->base.w || dot.y >= HEIGHT || dot.y < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y + dot.x * 4) = color;
	}
}
void				ft_print_line_img(t_pointers *p, t_dot dot, int color)
{
	int		lnx;
	int		lny;
	int		ln;

	lnx = ft_mod_num(p->dot_e.x - dot.x);
	lny = ft_mod_num(p->dot_e.y - dot.y);
	ln = ft_max(lnx, lny) + 1;
	if (dot.x < WIDTH && p->dot_e.x < WIDTH && dot.x >= p->base.w &&
		p->dot_e.x >= p->base.w && dot.y < HEIGHT && p->dot_e.y < HEIGHT
		&& dot.y >= 0 && p->dot_e.y >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y + dot.x * 4) = color;
	ft_cycle_of_print(p, dot, ln, color);
}
