/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:17 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/17 18:50:17 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot			*ft_list_create(int ln, char *line)
{
	t_dot				*new;
	__int128_t			num;
	int					i;

	if (!(new = malloc(sizeof(t_dot))))
		error("Error with malloc of list\n", 2);
	ft_memset(new, 0, sizeof(t_dot));
	new->ln = ln;
	if (!(new->array = malloc(sizeof(int) * ln)))
		error("Error with malloc of array in list\n", 2);
	i = 0;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		if (!ft_isdigit(*line) && *line != '-' && *line != '+')
			continue;
		num = ft_atoi(line);
		new->array[i] = num;
		if (num != new->array[i++])
			error("Overflow of int\n", 2);
		while (ft_isdigit(*line) || *line == '-' || *line == '+')
			line++;
	}
	return (new);
}

void			ft_list_add(t_dot *head, t_dot *new)
{
	t_dot *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}