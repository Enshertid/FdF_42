/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:11:52 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpopback(t_list **list)
{
	register t_list	*iter;
	t_list			*temp;

	if (!list || !*list)
		return ;
	iter = *list;
	temp = NULL;
	while (iter != (*list)->end)
	{
		temp = iter;
		iter = iter->next;
	}
	free(iter->content);
	free(iter);
	if (!temp)
		*list = NULL;
	else
		(*list)->end = temp;
}
