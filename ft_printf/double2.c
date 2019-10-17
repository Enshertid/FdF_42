/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:28:28 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		mult(char *str, unsigned long multiplier)
{
	unsigned long	add;
	unsigned long	add_prev;
	unsigned long	cur;

	add = 0;
	while (*(str) || add)
	{
		if (*str)
			*str -= '0';
		cur = (*str * multiplier) + add;
		add_prev = cur / 10;
		*str = '0' + cur % 10;
		add = add_prev;
		--str;
	}
}

void		add(char *str, char *plus)
{
	int add;
	int add_prev;
	int temp;

	add = 0;
	while (*plus || add)
	{
		if (*str != '.')
		{
			if (*str)
				*str -= '0';
			temp = *str + *plus + add;
			if (*plus)
				temp -= '0';
			add_prev = temp / 10;
			*str = '0' + temp % 10;
			add = add_prev;
			if (*plus)
				--plus;
		}
		--str;
	}
}

int			offset(int i)
{
	return ((i / 10) * 3 +
			((i % 10) / 4 ? 1 : 0) +
			((i % 10) / 7 ? 1 : 0) +
			(i / 970 - 1 + (i % 970 != 0)) +
			(i > 16380));
}
