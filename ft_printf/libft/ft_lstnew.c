/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:16:17 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_elem;

	if (!content)
		return (NULL);
	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new_elem->content = ft_memcpy(malloc(content_size),
									content, content_size)))
	{
		free(new_elem);
		return (NULL);
	}
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
