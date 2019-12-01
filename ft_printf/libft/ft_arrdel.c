/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:37:30 by dbendu            #+#    #+#             */
/*   Updated: 2019/11/29 14:46:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(void ***mem)
{
	size_t	iter;
	char	***arr;

	arr = (char***)mem;
	if (!arr || !*arr)
		return ;
	iter = 0;
	while ((*arr)[iter])
	{
		free((*arr)[iter]);
		(*arr)[iter] = NULL;
		++iter;
	}
	free(*arr);
	*arr = NULL;
}
