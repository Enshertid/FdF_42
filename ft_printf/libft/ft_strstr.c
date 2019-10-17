/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:27:28 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strptr, const char *findptr)
{
	const char	*str;
	const char	*find;

	if (findptr[0] == '\0')
		return ((char*)strptr);
	while (*strptr)
	{
		if (*strptr == *findptr)
		{
			str = strptr + 1;
			find = findptr + 1;
			while (*str && *str == *find)
			{
				++str;
				++find;
			}
			if (!*find)
				return ((char*)strptr);
		}
		++strptr;
	}
	return (NULL);
}
