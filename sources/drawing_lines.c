/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:31:04 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/17 15:38:51 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_print_line_img(t_pointers *p, t_dot dot_s, int color)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	lnx = ft_mod_num(p->dot_e.x - dot_s.x);
	lny = ft_mod_num(p->dot_e.y - dot_s.y);
	ln = ft_max(lnx, lny) + 1;
	d = ft_mod_num(p->dot_e.y - dot_s.y) <= ft_mod_num(p->dot_e.x - dot_s.x) ? -lnx : -lny;
	if (dot_s.x < HEIGHT && p->dot_e.x < HEIGHT && dot_s.x >= 0 && p->dot_e.x >= 0 &&
		dot_s.y < WIDTH && p->dot_e.y < WIDTH && dot_s.y >= 0 && p->dot_e.y >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color;
	while (ln--)
	{
		if (lny <= lnx)
			dot_s.x += p->dot_e.x - dot_s.x >= 0 ? 1 : -1;
		else
			dot_s.y += p->dot_e.y - dot_s.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot_s.y += p->dot_e.y - dot_s.y >= 0 ? 1 : -1;
			else
				dot_s.x += p->dot_e.x - dot_s.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dot_s.x >= WIDTH || dot_s.x < 0 ||
			dot_s.y >= HEIGHT || dot_s.y < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color;
	}
}

void			ft_use_grad(t_pointers *p)
{

}

void			ft_print_line_img_grad(t_pointers *p, t_dot dot_s, int color_s, int color_e)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;
	double	ln_a;

	lnx = ft_mod_num(p->dot_e.x - dot_s.x);
	lny = ft_mod_num(p->dot_e.y - dot_s.y);
	ln = ft_max(lnx, lny) + 1;
	d = ft_mod_num(p->dot_e.y - dot_s.y) <= ft_mod_num(p->dot_e.x - dot_s.x) ? -lnx : -lny;
	dot_s.r = color_s & 255;
	dot_s.g = (color_s >> 8) & 255;
	dot_s.b = (color_s >> 16) & 255;
	if (dot_s.x < WIDTH && p->dot_e.x < WIDTH && dot_s.x >= 0 && p->dot_e.x >= 0 &&
		dot_s.y < HEIGHT && p->dot_e.y < HEIGHT && dot_s.y >= 0 && p->dot_e.y >= 0)
	{
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = (int)dot_s.r;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.g << 8;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.b << 16;
	}
	ln_a = sqrt(lny * lny + lnx * lnx);
	p->color.i_r = abs(((color_e & 255) - (color_s  & 255))) / ln_a;
	p->color.i_g = abs(((color_e >> 8 & 255) - (color_s >> 8 & 255))) / ln_a;
	p->color.i_b = abs(((color_e >> 16 & 255) - (color_s  >> 16 & 255))) / ln_a;
	if ((color_e & 255) - (color_s  & 255) < 0)
		p->color.i_r = -p->color.i_r;
	if (((color_e >> 8 & 255) - (color_s  >> 8 & 255)) < 0)
		p->color.i_g = -p->color.i_g;
	if (((color_e >> 16 & 255) - (color_s  >> 16 & 255)) < 0)
		p->color.i_b = -p->color.i_b;
	dot_s.r += p->color.i_r;
	dot_s.g += p->color.i_g;
	dot_s.b += p->color.i_b;
	while (ln--)
	{
		if (lny <= lnx)
			dot_s.x += p->dot_e.x - dot_s.x >= 0 ? 1 : -1;
		else
			dot_s.y += p->dot_e.y - dot_s.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot_s.y += p->dot_e.y - dot_s.y >= 0 ? 1 : -1;
			else
				dot_s.x += p->dot_e.x - dot_s.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dot_s.x >= WIDTH || dot_s.x < 0 ||
			dot_s.y >= HEIGHT || dot_s.y < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = (int)dot_s.r ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.g << 8;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) += (int)dot_s.b << 16;
		dot_s.r += p->color.i_r;
		dot_s.g += p->color.i_g;
		dot_s.b += p->color.i_b;
	}

}
