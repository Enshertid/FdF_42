/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:11:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/01 14:21:21 by ymanilow         ###   ########.fr       */
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
	if (z != point->dot.z_min)
		z += point->dot.z;
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
			p->dot.x1 = i * p->dot.size + p->dot.start_x;
			p->dot.y1 = j * p->dot.size + p->dot.start_y;
			ft_iso(&p->dot.x1, &p->dot.y1, p->mtrx.array[j][i], p);
			p->dot.y2 = j * p->dot.size + p->dot.start_y;
			if (i != p->mtrx.ln_x - 1)
			{
				p->dot.x2 = (i + 1) * p->dot.size + p->dot.start_x;
				ft_iso(&p->dot.x2, &p->dot.y2, p->mtrx.array[j][i + 1], p);
				if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j][i + 1])
					ft_print_line_img(p, p->dot, p->dot.color);
				else
					ft_print_line_img(p, p->dot, WHITE_F);
			}
			p->dot.x2 = i * p->dot.size + p->dot.start_x;
			if (j != p->mtrx.ln_y - 1)
			{
				p->dot.y2 = (j + 1) * p->dot.size + p->dot.start_y;
				ft_iso(&p->dot.x2, &p->dot.y2, p->mtrx.array[j + 1][i], p);
				if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j + 1][i])
					ft_print_line_img(p, p->dot, p->dot.color);
				else
					ft_print_line_img(p, p->dot, WHITE_F);
			}
		}
		i = -1;
	}
}

void		ft_exept_first_dot(t_pointers *p, int i, int j)
{
	p->dot1.x1 = i * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
	p->dot1.y1 = j * p->dot.size - p->mtrx.ln_y / 2 * p->dot.size;
	ft_check_angle(p, &p->dot1.x1, &p->dot1.y1, &p->mtrx1.array[j][i]);
	p->dot1.x1 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
	p->dot1.y1 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
}

void		ft_exept_second_dot(t_pointers *p, int i, int j)
{
	if (i != p->mtrx1.ln_x - 1)
	{
		p->dot1.x2 = (i + 1) * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
		ft_check_angle(p, &p->dot1.x2, &p->dot1.y2, &p->mtrx1.array[j][i + 1]);
		p->dot1.x2 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
		p->dot1.y2 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
		p->mtrx1.array[j][i + 1] = p->mtrx.array[j][i + 1];
		if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j][i + 1])
			ft_print_line_img(p, p->dot1, p->dot.color);
		else
			ft_print_line_img(p, p->dot1, WHITE_F);
	}
	p->dot1.x2 = i * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
	if (j != p->mtrx1.ln_y - 1)
	{
		p->dot1.y2 = (j + 1) * p->dot.size - p->mtrx.ln_y / 2 * p->dot.size;
		ft_check_angle(p, &p->dot1.x2, &p->dot1.y2, &p->mtrx1.array[j + 1][i]);
		p->dot1.x2 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
		p->dot1.y2 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
		p->mtrx1.array[j + 1][i] = p->mtrx.array[j + 1][i];
		if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j + 1][i])
			ft_print_line_img(p, p->dot1, p->dot1.color);
		else
			ft_print_line_img(p, p->dot1, WHITE_F);
	}
}

void		ft_draw_matrix_img(t_pointers *p, int iso)
{
	int			i;
	int			j;
	int			flag;

	flag = 0;
	i = -1;
	j = -1;
	while (++j < p->mtrx1.ln_y)
	{
		while (++i < p->mtrx1.ln_x)
		{
			p->dot1.x1 = i * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
			p->dot1.y1 = j * p->dot.size - p->mtrx.ln_y / 2 * p->dot.size;
			ft_check_angle(p, &p->dot1.x1, &p->dot1.y1, &p->mtrx1.array[j][i]);
			p->dot1.x1 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
			p->dot1.y1 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
			p->dot1.y2 = j * p->dot.size - p->mtrx.ln_y / 2 * p->dot.size;
			if (i != p->mtrx1.ln_x - 1)
			{
				p->dot1.x2 = (i + 1) * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
				ft_check_angle(p, &p->dot1.x2, &p->dot1.y2, &p->mtrx1.array[j][i + 1]);
				p->dot1.x2 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
				p->dot1.y2 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
				p->mtrx1.array[j][i + 1] = p->mtrx.array[j][i + 1];
//				if (p->dot1.x1 > 2000 || p->dot1.x2 > 2000 || p->dot1.x1 < 0 || p->dot1.x2 < 0 ||
//				p->dot1.y1 > 2000 || p->dot1.y2 > 2000 || p->dot1.y1 < 0 || p->dot1.y2 < 0)
//					continue ;
				if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j][i + 1])
					ft_print_line_img(p, p->dot1, p->dot.color);
				else
					ft_print_line_img(p, p->dot1, WHITE_F);
			}
			p->dot1.x2 = i * p->dot.size - p->mtrx.ln_x / 2 * p->dot.size;
			if (j != p->mtrx1.ln_y - 1)
			{
				p->dot1.y2 = (j + 1) * p->dot.size - p->mtrx.ln_y / 2 * p->dot.size;
				ft_check_angle(p, &p->dot1.x2, &p->dot1.y2, &p->mtrx1.array[j + 1][i]);
				p->dot1.x2 += p->dot.start_x + p->mtrx.ln_x / 2 * p->dot.size;
				p->dot1.y2 += p->dot.start_y + p->mtrx.ln_y / 2 * p->dot.size;
				p->mtrx1.array[j + 1][i] = p->mtrx.array[j + 1][i];
//				if (p->dot1.x1 > 2000 || p->dot1.x2 > 2000 || p->dot1.x1 < 0 || p->dot1.x2 < 0 ||
//					p->dot1.y1 > 2000 || p->dot1.y2 > 2000 || p->dot1.y1 < 0 || p->dot1.y2 < 0)
//					continue;
				if (p->mtrx.array[j][i] != 0 || p->mtrx.array[j + 1][i])
					ft_print_line_img(p, p->dot1, p->dot1.color);
				else
					ft_print_line_img(p, p->dot1, WHITE_F);
			}
		}
//		if (flag == 1)
//			break ;
		i = -1;
	}
}

void			ft_print_line_img(t_pointers *p, t_dot dot, int color)
{
	int		lnx;
	int		lny;
	int		ln;
	int		d;

	lnx = ft_mod_num(dot.x2 - dot.x1);
	lny = ft_mod_num(dot.y2 - dot.y1);
	ln = ft_max(lnx, lny) + 1;
	d = m_n(dot.y2 - dot.y1) <= m_n(dot.x2 - dot.x1) ? -lnx : -lny;
	if (dot.x1 < 2000 && dot.x2 < 2000 && dot.x1 >= 0 && dot.x2 >= 0 &&
		dot.y1 < 2000 && dot.y2 < 2000 && dot.y1 >= 0 && dot.y2 >= 0)
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y1 + dot.x1 * 4) = color;
	while (ln--)
	{
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
		if (dot.x1 >= 2000 || dot.x1 < 0 ||
			dot.y1 >= 2000 || dot.y1 < 0)
			continue ;
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y1 + dot.x1 * 4) = color;
	}
}
