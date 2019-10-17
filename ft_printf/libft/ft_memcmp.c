/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:04 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	register const unsigned char *str1;
	register const unsigned char *str2;

	str1 = (const unsigned char*)memptr1;
	str2 = (const unsigned char*)memptr2;
	while (num-- > 0)
		if (*str1++ != *str2++)
			return ((unsigned char)str1[-1] - (unsigned char)str2[-1]);
	return (0);
}
