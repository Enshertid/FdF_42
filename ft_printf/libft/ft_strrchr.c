/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:27:04 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*found;
	const char	*p;

	ch = (unsigned char)ch;
	if (ch == '\0')
		return (ft_strchr(str, '\0'));
	found = NULL;
	while ((p = ft_strchr(str, ch)) != NULL)
	{
		found = p;
		str = p + 1;
	}
	return ((char*)found);
}
