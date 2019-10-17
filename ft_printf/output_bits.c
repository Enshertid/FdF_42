/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:02:20 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_binary(char *ptr, t_spec *format)
{
	char	*str;
	size_t	size;
	size_t	pos;
	int		bit;

	size = ft_max(format->width, format->precision);
	pos = size;
	str = (char*)malloc(size * 8 + size);
	while (size--)
		ft_memcpy((str += 9) - 9, "00000000 ", 9);
	(str -= pos * 9)[pos * 9 - 1] = '\0';
	pos = (format->width > format->precision && !format->flag_minus) *
			(format->width - format->precision) * 9;
	while (format->precision--)
	{
		bit = 128;
		while (bit)
		{
			str[pos++] = '0' + (*(ptr + format->precision) & bit ? 1 : 0);
			bit >>= 1;
		}
		++pos;
	}
	return (str);
}
