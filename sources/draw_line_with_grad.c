/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:58:23 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/18 13:11:15 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_add_pixel(t_pointers *p, t_dot dot_s)
{
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4)
							= (int)dot_s.r;
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4)
							+= (int)dot_s.g << 8;
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4)
							+= (int)dot_s.b << 16;
}

void				ft_funct_for_grad(t_pointers *p, int color_s,
								int color_e, t_dot *dot)
{
	int		lnx;
	int		lny;
	double	ln_a;

	lnx = ft_mod_num(p->dot_e.x - dot->x);
	lny = ft_mod_num(p->dot_e.y - dot->y);
	dot->r = color_s & 255;
	dot->g = (color_s >> 8) & 255;
	dot->b = (color_s >> 16) & 255;
	if (dot->x < WIDTH && p->dot_e.x < WIDTH && dot->x >= p->base.w &&
	p->dot_e.x >= p->base.w && dot->y < HEIGHT &&
	p->dot_e.y < HEIGHT && dot->y >= 0 && p->dot_e.y >= 0)
		ft_add_pixel(p, *dot);
	ln_a = sqrt(lny * lny + lnx * lnx);
	p->color.i_r = abs(((color_e & 255) - (color_s & 255))) / ln_a;
	p->color.i_g = abs(((color_e >> 8 & 255) - (color_s >> 8 & 255))) / ln_a;
	p->color.i_b = abs(((color_e >> 16 & 255) - (color_s >> 16 & 255))) / ln_a;
	if ((color_e & 255) - (color_s  & 255) < 0)
		p->color.i_r = -p->color.i_r;
	if (((color_e >> 8 & 255) - (color_s  >> 8 & 255)) < 0)
		p->color.i_g = -p->color.i_g;
	if (((color_e >> 16 & 255) - (color_s  >> 16 & 255)) < 0)
		p->color.i_b = -p->color.i_b;
	dot->r += p->color.i_r;
	dot->g += p->color.i_g;
	dot->b += p->color.i_b;
}

void				ft_cycle_cost(t_pointers *p, t_dot *dot_s)
{
	*(int*)(p->img.char_ptr + p->img.ln_size *
	dot_s->y + dot_s->x * 4) = (int)dot_s->r;
	*(int*)(p->img.char_ptr + p->img.ln_size *
	dot_s->y + dot_s->x * 4) += (int)dot_s->g << 8;
	*(int*)(p->img.char_ptr + p->img.ln_size *
	dot_s->y + dot_s->x * 4) += (int)dot_s->b << 16;
	dot_s->r += p->color.i_r;
	dot_s->g += p->color.i_g;
	dot_s->b += p->color.i_b;
}

int					ft_size_of_step(t_pointers *p, int *lnx, int *lny, int *ln)
{
	int d;

	*lnx = ft_mod_num(p->dot_e.x - p->dot_s.x);
	*lny = ft_mod_num(p->dot_e.y - p->dot_s.y);
	*ln = ft_max(*lnx, *lny) + 1;
	d = *lny <= *lnx ? -*lnx : -*lny;
	return (d);
}

void			ft_print_line_img_grad(t_pointers *p, t_dot dot,
										int color_s, int color_e)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	d = ft_size_of_step(p, &lnx, &lny, &ln);
	ft_funct_for_grad(p, color_s, color_e, &dot);
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
		ft_cycle_cost(p, &dot);
	}
}
