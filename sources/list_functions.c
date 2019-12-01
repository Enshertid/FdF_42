/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:17 by ymanilow          #+#    #+#             */
/*   Updated: 2019/11/29 14:46:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matr			*ft_list_create(int ln, char *line)
{
	t_matr				*new;
	__int128_t			num;
	int					i;

	if (!(new = malloc(sizeof(t_matr))))
		error("Error with malloc of list\n", 2);
	ft_memset(new, 0, sizeof(t_matr));
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

void			ft_list_add(t_matr *head, t_matr *new)
{
	t_matr *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}