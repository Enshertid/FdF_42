/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:11:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/02 13:23:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				m_n(int num)
{
	return (num > 0 ? num : -num);
}

void		ft_iso(int *x, int *y, int z, t_pointers *point)
{
	int start_x;
	int start_y;
	
	start_x = *x;
	start_y = *y;
	if (z != point->base.z_min)
		z += point->base.z_p;
	*x = (start_x - start_y) * 0.86632463631;
	*y = (-z + (start_x + start_y) * 0.50000019433);
}

void		ft_draw_matrix_img_iso(t_pointers *p)
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
//				if (p->mtrx.array[j][i] != p->dot.z_min || p->mtrx.array[j][i + 1] != p->dot.z_min)
//					ft_print_line_img(p, p->dot, p->mtrx.color[j][i]);
//				else
					ft_print_line_img(p, p->dot_s, p->dot_e, p->mtrx.color[j][i]);
			}
			p->dot_e.x = i * p->base.size + p->base.start_x;
			if (j != p->mtrx.ln_y - 1)
			{
				p->dot_e.y = (j + 1) * p->base.size + p->base.start_y;
				ft_iso(&p->dot_e.x, &p->dot_e.y, p->mtrx.array[j + 1][i], p);
//				if (p->mtrx.array[j][i] != p->dot.z_min || p->mtrx.array[j + 1][i] != p->dot.z_min)
//					ft_print_line_img(p, p->dot, p->mtrx.color[j + 1][i]);
//				else
					ft_print_line_img(p, p->dot_s, p->dot_e, p->mtrx.color[j][i]);
			}
		}
		i = -1;
	}
}

void		ft_exept_first_dot(t_pointers *p, int i, int j)
{
	p->dot_s.x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
	p->dot_s.y = j * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
	ft_check_angle(p, &p->dot_s.x, &p->dot_e.y, &p->mtrx.array[j][i]);
	p->dot_s.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
	p->dot_s.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
}

void		ft_exept_second_dot(t_pointers *p, int i, int j)
{
	if (i != p->mtrx.ln_x - 1)
	{
		p->dot_e.x = (i + 1) * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
		ft_check_angle(p, &p->dot_e.x, &p->dot_e.y, &p->mtrx.array[j][i + 1]);
		p->dot_e.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
		p->dot_e.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
		p->mtrx.array[j][i + 1] = p->mtrx.array[j][i + 1];
		if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j][i + 1])
			ft_print_line_img(p, p->dot_s, p->dot_e, p->base.color);
		else
			ft_print_line_img(p, p->dot_s, p->dot_e, WHITE_F);
	}
	p->dot_e.x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
	if (j != p->mtrx.ln_y - 1)
	{
		p->dot_e.y = (j + 1) * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
		ft_check_angle(p, &p->dot_e.x, &p->dot_e.y, &p->mtrx.array[j + 1][i]);
		p->dot_e.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
		p->dot_e.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
		p->mtrx.array[j + 1][i] = p->mtrx.array[j + 1][i];
		if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j + 1][i])
			ft_print_line_img(p, p->dot_s, p->dot_e, p->base.color);
		else
			ft_print_line_img(p, p->dot_s, p->dot_e, WHITE_F);
	}
}

void		ft_draw_matrix_img(t_pointers *p)
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
				if (p->mtrx.array[j][i] != p->base.z_min || p->mtrx.array[j][i + 1] != p->base.z_min)
					ft_print_line_img_grad(p, p->dot_s, p->dot_e, WHITE_F, RED_F);
				else
					ft_print_line_img(p, p->dot_s, p->dot_e, WHITE_F);
			}
			if (j != p->mtrx.ln_y - 1)
			{
				p->dot_e.x = i * p->base.size - p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.y = (j + 1) * p->base.size - p->mtrx.ln_y / 2 * p->base.size;
				p->dot_e.z = p->mtrx.array[j + 1][i];
				ft_check_angle(p, &p->dot_e.x, &p->dot_e.y, &p->dot_e.z);
				p->dot_e.x += p->base.start_x + p->mtrx.ln_x / 2 * p->base.size;
				p->dot_e.y += p->base.start_y + p->mtrx.ln_y / 2 * p->base.size;
				if (p->mtrx.array[j][i] != p->base.z_min || p->mtrx.array[j + 1][i] != p->base.z_min)
					ft_print_line_img_grad(p, p->dot_s, p->dot_e, WHITE_F, RED_F);
				else
					ft_print_line_img(p, p->dot_s, p->dot_e,  WHITE_F);
			}
		}
		i = -1;
	}
}

void			ft_print_line_img(t_pointers *p, t_dot dot_s, t_dot dot_e, int color)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	lnx = ft_mod_num(dot_e.x - dot_s.x);
	lny = ft_mod_num(dot_e.y - dot_s.y);
	ln = ft_max(lnx, lny) + 1;
	d = m_n(dot_e.y - dot_s.y) <= m_n(dot_e.x - dot_s.x) ? -lnx : -lny;
	if (dot_s.x < 2000 && dot_e.x < 2000 && dot_s.x >= 0 && dot_e.x >= 0 &&
		dot_s.y < 2000 && dot_e.y < 2000 && dot_s.y >= 0 && dot_e.y >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color;
	while (ln--)
	{
		if (lny <= lnx)
			dot_s.x += dot_e.x - dot_s.x >= 0 ? 1 : -1;
		else
			dot_s.y += dot_e.y - dot_s.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot_s.y += dot_e.y - dot_s.y >= 0 ? 1 : -1;
			else
				dot_s.x += dot_e.x - dot_s.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dot_s.x >= 2000 || dot_s.x < 0 ||
			dot_s.y >= 2000 || dot_s.y < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color;
	}
}

void			ft_print_line_img_grad(t_pointers *p, t_dot dot_s, t_dot dot_e, double color_start, double color_end)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;
	double	iter_b;
	double	iter_g;
	double	iter_r;

	lnx = ft_mod_num(dot_e.x - dot_s.x);
	lny = ft_mod_num(dot_e.y - dot_s.y);
	ln = ft_max(lnx, lny) + 1;
	d = m_n(dot_e.y - dot_s.y) <= m_n(dot_e.x - dot_s.x) ? -lnx : -lny;
	if (dot_s.x < 2000 && dot_e.x < 2000 && dot_s.x >= 0 && dot_e.x >= 0 &&
		dot_s.y < 2000 && dot_e.y < 2000 && dot_s.y >= 0 && dot_e.y >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color_start;
	iter_r = (((int)color_start >> 8 & 255) - ((int)color_end >> 8 & 255))/ (ln - 1);
	iter_g = (((int)color_start >> 16 & 255) - ((int)color_end >> 16 & 255)) / (ln - 1);
	iter_b = (((int)color_start >> 24 & 255) - ((int)color_end >> 24 & 255)) / (ln - 1);
	color_start += (int)iter_r << 8;
	color_start += (int)iter_g << 16;
	color_start += (int)iter_b << 24;
	while (ln--)
	{
		if (lny <= lnx)
			dot_s.x += dot_e.x - dot_s.x >= 0 ? 1 : -1;
		else
			dot_s.y += dot_e.y - dot_s.y >= 0 ? 1 : -1;
		if ((d += lny <= lnx ? 2 * lny : 2 * lnx) > 0)
		{
			if (lny <= lnx)
				dot_s.y += dot_e.y - dot_s.y >= 0 ? 1 : -1;
			else
				dot_s.x += dot_e.x - dot_s.x >= 0 ? 1 : -1;
			d -= lny <= lnx ? 2 * lnx : 2 * lny;
		}
		if (dot_s.x >= 2000 || dot_s.x < 0 ||
			dot_s.y >= 2000 || dot_s.y < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot_s.y + dot_s.x * 4) = color_start;
		color_start += (int)iter_r << 8;
		color_start += (int)iter_g << 16;
		color_start += (int)iter_b << 24;
	}
}