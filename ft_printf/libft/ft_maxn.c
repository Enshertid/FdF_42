/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:49 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxn(int amount, ...)
{
	int		i;
	int		temp;
	int		max_num;
	va_list	argptr;

	if (!amount)
		return (MAX_INT);
	i = 0;
	va_start(argptr, amount);
	while (i < amount)
	{
		temp = va_arg(argptr, int);
		if (!i || temp > max_num)
			max_num = temp;
		++i;
	}
	va_end(argptr);
	return (max_num);
}
