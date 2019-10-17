/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:34 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*src;
	char	*dst;
	size_t	i;

	if (!destptr && !srcptr)
		return (NULL);
	i = -1;
	src = (char *)srcptr;
	dst = (char *)destptr;
	if (src < dst)
		while ((int)(--num) >= 0)
			*(dst + num) = *(src + num);
	else
		while (++i < num)
			*(dst + i) = *(src + i);
	return (destptr);
}
