/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:31:04 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 20:48:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_cycle(t_pointers *p, t_dot dot, int ln, int color)
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
		if (dot.x >= WIDTH || dot.x < 0 || dot.y >= HEIGHT || dot.y < 0)
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
	if (dot.x < HEIGHT && p->dot_e.x < HEIGHT && dot.x >= 0 && p->dot_e.x >= 0 &&
		dot.y < WIDTH && p->dot_e.y < WIDTH && dot.y >= 0 && p->dot_e.y >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y + dot.x * 4) = color;
	ft_cycle(p, dot, ln, color);
}

void			ft_add_pixel(t_pointers *p, t_dot dot_s)
{
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = (int)dot_s.r;				//в текущий
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.g << 8;			//пиксель цвета
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.b << 16;		//добавляем
}

void			ft_funct(t_pointers *p, int color_s, int color_e, t_dot *dot_s)
{
	int		lnx;
	int		lny;
	double	ln_a;

	lnx = ft_mod_num(p->dot_e.x - dot_s->x);
	lny = ft_mod_num(p->dot_e.y - dot_s->y);
	dot_s->r = color_s & 255;						//
	dot_s->g = (color_s >> 8) & 255;					// раскладываем наш начальный цвет на rgb
	dot_s->b = (color_s >> 16) & 255;				//
	if (dot_s->x < WIDTH && p->dot_e.x < WIDTH && dot_s->x >= 0 && p->dot_e.x >= 0 &&
		dot_s->y < HEIGHT && p->dot_e.y < HEIGHT && dot_s->y >= 0 && p->dot_e.y >= 0)
		ft_add_pixel(p, *dot_s);
	ln_a = sqrt(lny * lny + lnx * lnx); // находим гипотенузу (длину отрезка)
	p->color.i_r = abs(((color_e & 255) - (color_s  & 255))) / ln_a;					//
	p->color.i_g = abs(((color_e >> 8 & 255) - (color_s >> 8 & 255))) / ln_a;			//
	p->color.i_b = abs(((color_e >> 16 & 255) - (color_s  >> 16 & 255))) / ln_a;		//
	if ((color_e & 255) - (color_s  & 255) < 0)
		p->color.i_r = -p->color.i_r;
	if (((color_e >> 8 & 255) - (color_s  >> 8 & 255)) < 0)
		p->color.i_g = -p->color.i_g;
	if (((color_e >> 16 & 255) - (color_s  >> 16 & 255)) < 0)
		p->color.i_b = -p->color.i_b;
	dot_s->r += p->color.i_r;
	dot_s->g += p->color.i_g;
	dot_s->b += p->color.i_b;
}

void			ft_cycle_cost(t_pointers *p, t_dot *dot_s)
{
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s->y + dot_s->x * 4) = (int)dot_s->r;
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s->y + dot_s->x * 4) += (int)dot_s->g << 8;
	*(int*)(p->img.char_ptr + p->img.ln_size * dot_s->y + dot_s->x * 4) += (int)dot_s->b << 16;
	dot_s->r += p->color.i_r;
	dot_s->g += p->color.i_g;
	dot_s->b += p->color.i_b;
}

int			ft_costylishe(t_pointers *p, int *lnx, int *lny, int *ln)
{
	int d;

	*lnx = ft_mod_num(p->dot_e.x - p->dot_s.x);
	*lny = ft_mod_num(p->dot_e.y - p->dot_s.y);
	*ln = ft_max(*lnx, *lny) + 1;
	d = *lny <= *lnx ? -*lnx : -*lny;
	return (d);
}

void			ft_print_line_img_grad(t_pointers *p, t_dot dots, int color_s, int color_e)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	d = ft_costylishe(p, &lnx, &lny, &ln);
	ft_funct(p, color_s, color_e, &dots);
	while (ln--)
	{
		if (lny <= lnx)
			dots.x += p->dot_e.x - dots.x >= 0 ? 1 : -1;
		else
			dots.y += p->dot_e.y - dots.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dots.y += p->dot_e.y - dots.y >= 0 ? 1 : -1;
			else
				dots.x += p->dot_e.x - dots.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dots.x >= WIDTH || dots.x < 0 || dots.y >= HEIGHT || dots.y < 0)
			continue ;
		ft_cycle_cost(p, &dots);
	}
}
