/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:05:33 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **list)
{
	t_list *temp;

	if (!list || !*list)
		return ;
	if ((*list)->next)
		(*list)->next->end = (*list)->end;
	temp = (*list)->next;
	free((*list)->content);
	free(*list);
	*list = temp;
}
