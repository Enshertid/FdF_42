/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:16:43 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *deststr, const void *srcstr, int ch, size_t count)
{
	register unsigned char *dest;
	register unsigned char *src;
	register unsigned char stop;

	dest = (unsigned char*)deststr;
	src = (unsigned char*)srcstr;
	stop = ch;
	while (count--)
		if ((*dest++ = *src++) == stop)
			return (dest);
	return (NULL);
}
