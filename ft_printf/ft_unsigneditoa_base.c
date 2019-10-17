/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:19:40 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_checklenght(ULL num, int base)
{
	unsigned		i;

	i = 0;
	while (num /= base)
		i++;
	return (i + 1);
}

char			*ft_unsigned_itoa_base(ULL num, int base, unsigned size)
{
	char				*s;
	char				*base_ar;
	unsigned int		lenght;

	lenght = ft_checklenght(num, base);
	if (base == 16)
		base_ar = (size == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	else if (base == 8)
		base_ar = "01234567";
	else if (base == 10)
		base_ar = "0123456789";
	else
		return ("check base");
	s = ft_memalloc(lenght + 1);
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[--lenght] = base_ar[num % base];
		num /= base;
	}
	return (s);
}
