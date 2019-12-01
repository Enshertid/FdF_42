/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:13:17 by user              #+#    #+#             */
/*   Updated: 2019/11/29 14:46:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	sizeof_num(__int128_t num, unsigned base)
{
	size_t size;

	if (!num)
		return (1);
	if (base == 10 && num < 0)
		num = -num;
	size = 0;
	while (num)
	{
		++size;
		num /= base;
	}
	return (size);
}
