/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:51:34 by user              #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_buf(__int128_t num, char *str, unsigned base,
					unsigned is_upper)
{
	const char	*alphabet = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char		*iter;

	iter = str;
	if (base == 10 && num < 0)
	{
		*iter++ = '-';
		num = -num;
	}
	if (!num)
		*iter++ = '0';
	while (num)
	{
		*iter++ = alphabet[num % base];
		num /= base;
	}
	*iter = '\0';
	ft_strrev(str + (*str == '-'));
	return (str);
}

static void		ft_isnegative_topos(long long int *num, size_t *is_negative)
{
	if (*num < 0)
	{
		*is_negative = 1;
		*num = -*num;
	}
	else
		*is_negative = 0;
}

static size_t	ft_size_of_num(long long int n)
{
	size_t size;

	size = 0;
	while (n /= 10)
		++size;
	return (size + 1);
}

char			*ft_itoa(long long int num)
{
	register char	*str;
	register size_t	size;
	size_t			sign;

	if (num == (-MAX_LLONG - 1LL))
		return (ft_strdup("-9223372036854775808"));
	size = ft_size_of_num(num) + 1 + (num < 0);
	ft_isnegative_topos(&num, &sign);
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (size--)
	{
		str[size] = (num % 10 + 48);
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
