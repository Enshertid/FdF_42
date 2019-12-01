/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:34:18 by dbendu            #+#    #+#             */
/*   Updated: 2019/11/29 14:46:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	iter;

	if (!str)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	iter = -1;
	str += start;
	while (++iter < len && str[iter] != '\0')
		result[iter] = str[iter];
	result[iter] = '\0';
	return (result);
}
