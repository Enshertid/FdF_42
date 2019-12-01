/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:49:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/11/29 14:46:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstextend(t_list **list, t_list **add)
{
	if (!list || !add)
		return ;
	if (*list)
	{
		if (*add)
		{
			(*list)->end->next = *add;
			(*list)->end = (*add)->end;
		}
	}
	else if (*add)
		*list = *add;
}
