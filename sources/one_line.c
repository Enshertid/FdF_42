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

int				m_n(int num)
{
	return (num > 0 ? num : -num);
}

void		ft_draw_matrix_pp(t_pointers *point, int iso)
{
	int			i;
	int			j;
	t_matr		*tmp;
	
	i = 1;
	j = 1;
	tmp = point->matr;
	while (j <= point->mtrx.ln_y)
	{
		while (i <= point->matr->ln)
		{
			point->dot.x1 = i * point->dot.size + point->dot.start_x;
			point->dot.y1 = j * point->dot.size + point->dot.start_y;
			if (iso == 1)
			{
				ft_iso(&point->dot.x1, &point->dot.y1, tmp->array[i - 1], point);
				point->dot.y1 -= point->matr->array[i - 1] * point->dot.size * 10;
			}
			point->dot.y2 = j * point->dot.size + point->dot.start_y;
			if (i != point->matr->ln)
			{
				point->dot.x2 = (i + 1) * point->dot.size + point->dot.start_x;
				if (iso == 1)
				{
					ft_iso(&point->dot.x2, &point->dot.y2, tmp->array[i - 1], point);
					point->dot.y2 -= point->matr->array[i - 1] *  point->dot.size * 10;
				}
				ft_print_line_pp(point, point->dot, 0xFFFF00);
			}
			point->dot.x2 = i * point->dot.size + point->dot.start_x;
			if (j != point->mtrx.ln_y)
			{
				point->dot.y2 = (j + 1) * point->dot.size + point->dot.start_y;
				if (iso == 1)
				{
					ft_iso(&point->dot.x2, &point->dot.y2, tmp->array[i - 1], point);
					point->dot.y2 -= point->matr->array[i - 1]  * point->dot.size * 10;
				}
				ft_print_line_pp(point, point->dot, 0xFFFFFF);
			}
			i++;
		}
		i = 1;
		j++;
	}
}

void			ft_print_line_pp(t_pointers *p, t_dot dot, int color)
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

void		ft_iso(int *x, int *y, int z, t_pointers *point)
{
	int start_x;
	int start_y;
	
	start_x = *x;
	start_y = *y;
	if (z != 0)
		 z += point->dot.z;
	*x = (start_x - start_y) * 0.86632463631;
	*y = (-z + (start_x + start_y) * 0.50000019433);
}

void		ft_draw_matrix_img_iso(t_pointers *point)
{
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	while (j < point->mtrx.ln_y)
	{
		while (i < point->mtrx.ln_x)
		{
			point->dot.x1 = i * point->dot.size + point->dot.start_x;
			point->dot.y1 = j * point->dot.size + point->dot.start_y;
			ft_iso(&point->dot.x1, &point->dot.y1, point->mtrx.array[j][i], point);
			point->dot.y2 = j * point->dot.size + point->dot.start_y;
			if (i != point->mtrx.ln_x - 1)
			{
				point->dot.x2 = (i + 1) * point->dot.size + point->dot.start_x;
				ft_iso(&point->dot.x2, &point->dot.y2, point->mtrx.array[j][i + 1], point);
				if (point->mtrx.array[j][i] != 0 || point->mtrx.array[j][i + 1])
					ft_print_line_img(point, point->dot, 0xFF00FF);
				else
					ft_print_line_img(point, point->dot, 0xFFFFFF);
			}
			point->dot.x2 = i * point->dot.size + point->dot.start_x;
			if (j != point->mtrx.ln_y - 1)
			{
				point->dot.y2 = (j + 1) * point->dot.size + point->dot.start_y;
				ft_iso(&point->dot.x2, &point->dot.y2, point->mtrx.array[j + 1][i], point);
				if (point->mtrx.array[j][i] != 0 || point->mtrx.array[j + 1][i])
					ft_print_line_img(point, point->dot, 0xFF00FF);
				else
					ft_print_line_img(point, point->dot, 0xFFFFFF);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void		ft_draw_matrix_img(t_pointers *point, int iso)
{
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	while (j < point->mtrx.ln_y)
	{
		while (i < point->mtrx.ln_x)
		{
			point->dot.x1 = i * point->dot.size + point->dot.start_x;
			point->dot.y1 = j * point->dot.size + point->dot.start_y;
			point->dot.y2 = j * point->dot.size + point->dot.start_y;
			if (i != point->mtrx.ln_x - 1)
			{
				point->dot.x2 = (i + 1) * point->dot.size + point->dot.start_x;
				if (point->mtrx.array[j][i] != 0 || point->mtrx.array[j][i + 1])
					ft_print_line_img(point, point->dot, 0xFF00FF);
				else
					ft_print_line_img(point, point->dot, 0xFFFFFF);
			}
			point->dot.x2 = i * point->dot.size + point->dot.start_x;
			if (j != point->mtrx.ln_y - 1)
			{
				point->dot.y2 = (j + 1) * point->dot.size + point->dot.start_y;
				if (point->mtrx.array[j][i] != 0 || point->mtrx.array[j + 1][i])
					ft_print_line_img(point, point->dot, 0xFF00FF);
				else
					ft_print_line_img(point, point->dot, 0xFFFFFF);
			}
			i++;
		}
		i = 0;
		j++;
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
	while (ln--)
	{
		*(int*)(p->img.char_ptr + p->img.ln_size * dot.y1 + dot.x1 * 4) = color;
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
