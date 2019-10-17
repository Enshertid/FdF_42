/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:13:41 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/17 11:43:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_dot
{
	int			x;
	int			y;
	int			z;
	int			num;
	struct s_dot *next;
} t_dot;

typedef struct	s_pointers
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_pointers;

int				deal_key(int key, void *param);

#endif
