/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:38 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/17 11:43:05 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int		deal_key(int key, void *param)
{
	ft_printf("%d", key);
	return (0);
}

t_dot		*ft_dot_create(int x, int y, int z)
{
	t_dot *dot;

	if (!(dot = malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->z = z;
	dot->num = 1;
	dot->next = NULL;
	return (dot);
}

void		ft_dot_add(t_dot **head, t_dot *new)
{
	t_dot *tmp;
	int num;

	num = 1;
	tmp = *head;
	if (!tmp->next)
	{
		tmp->next = new;
		new->num = 2;
	}
	else
	{
		while (tmp)
		{
			ft_printf("11\n\n\n");
			num++;
			tmp = tmp->next;
		}
		new->num = num;
		tmp->next = new;
	}
}

int			ft_mod_num(int num)
{
	return (num < 0 ? -num : num);
}

//void		ft_print_line(int start_x, int start_y, int end_x, int end_y, t_pointers *point)
//{
//	int		a;
//	int		b;
//	int		f;
//	int sign_a;
//	int sign_b;
//
//	f = 0;
//	a = end_y - start_y;
//	b = start_x - end_x;
//	sign_a = a < 0 ? -1 : 1;
//	sign_b = b < 0 ? -1 : 1;
//	a = ft_mod_num(a);
//	b = ft_mod_num(b);
//	mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xABCFFF);
//	while (start_x != end_x && start_x != end_y)
//	{
//		if (a < b)
//		{
//			f += a;
//			if (f > 0)
//			{
//				f -= b;
//				start_y += sign_a;
//			}
//			start_x -= sign_b;
//			mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xABCFFF);
//		}
//		else
//		{
//			f += b;
//			if (f > 0)
//			{
//				f -= a;
//				start_x -= sign_b;
//			}
//			start_y += sign_a;
//			mlx_pixel_put(point->mlx_ptr, point->win_ptr, start_x, start_y, 0xBCAFFF);
//		}
//	}
//}


int		main()
{
	t_pointers	point;
	t_dot		*dot;

	dot = NULL;
	dot = ft_dot_create(500, 500, 0);
	ft_dot_add(&dot, ft_dot_create(675, 700, 0));
	point.mlx_ptr = mlx_init();
	point.win_ptr = mlx_new_window(point.mlx_ptr, 1000, 1000, "My_first_window");
	ft_print_line(900, 900, 325, 325, &point);
	mlx_key_hook(point.win_ptr, deal_key, (void*)0);
	mlx_mouse_hook(point.win_ptr, deal_key, (void*)0);
	mlx_loop(point.mlx_ptr);
	return (0);
}
