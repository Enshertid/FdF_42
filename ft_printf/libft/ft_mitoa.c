/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:14:35 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mitoa(__int128_t num, unsigned base, unsigned is_upper)
{
	const char	*alphabet = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char		*result;
	size_t		pos;

	if (num == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (base < 2 || base > 16 ||
		!(result = ft_strnew(sizeof_num(num, base))))
		return (NULL);
	pos = 0;
	if (base == 10 && num < 0)
	{
		num = -num;
		result[pos++] = '-';
	}
	result[pos] = '0';
	while (num)
	{
		result[pos++] = alphabet[num % base];
		num /= base;
	}
	ft_strrev(result + (result[0] == '-'));
	return (result);
}
