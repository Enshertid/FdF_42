/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:24:48 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	register char	*new_str;
	size_t			iter;

	if (!str || !f)
		return (NULL);
	new_str = (char*)malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	iter = -1;
	while (str[++iter])
		new_str[iter] = f(iter, str[iter]);
	new_str[iter] = '\0';
	return (new_str);
}
