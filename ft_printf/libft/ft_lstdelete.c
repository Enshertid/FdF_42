/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:47:22 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_replace(t_list **to, t_list **from)
{
	free((*to)->content);
	(*to)->content = (*from)->content;
	(*to)->content_size = (*from)->content_size;
	(*to)->next = (*from)->next;
	free(*from);
}

void		ft_lstdelete(t_list **list, t_list **del)
{
	t_list *iter;

	if (!list || !*list || !del || !*del)
		return ;
	if (*del == (*list))
		ft_lstpop(list);
	else if (*del == (*list)->end)
		ft_lstpopback(list);
	else
	{
		iter = *list;
		while (iter && iter != *del)
			iter = iter->next;
		if (iter)
			ft_replace(&iter, &(iter->next));
	}
}
