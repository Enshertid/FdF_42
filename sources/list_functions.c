/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:17 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/02 12:04:26 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int hex_to_dec(const char *str)
{
	const char *alphabet = "0123456789abcdef";
	const char *iter;
	int mult;
	int res;
	int pos;

	iter = str;
	while (ft_isdigit(*iter) ||
		   (ft_tolower(*iter) >= 'a' && ft_tolower(*iter) <= 'f'))
		++iter;
	res = 0;
	mult = 1;
	--iter;
	while (iter >= str)
	{
		pos = (char*)ft_memchr(alphabet, ft_tolower(*iter), 16) - alphabet;
		res += mult * pos;
		mult *= 16;
		--iter;
	}
	return (res);
}

int			ft_fill_color(t_matr *new, char *line, char *s)
{
	int		j;
	int		i;

	j = 0;
	line++;
	while (*line == '0' || *line == 'x')
		s[j++] = *line++;
	while (ft_isdigit(*line) || ft_is_hex(*line))
		s[j++] = *line++;
	i = 0;
	new->color[i] = hex_to_dec(s);
	return (j);
}

void		ft_fill_array_of_list(t_matr *new, char *line,
									__int128_t num, char *s)
{
	int i;

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
		if (*line == ',')
			line += ft_fill_color(new, line, s);
	}
}

t_matr			*ft_list_create(int ln, char *line)
{
	char				*s;
	t_matr				*new;
	__int128_t			num;

	s = malloc(sizeof(char*) * 9);
	s[8] = '\0';
	if (!(new = malloc(sizeof(t_matr))))
		error("Error with malloc of list\n", 2);
	ft_memset(new, 0, sizeof(t_matr));
	new->ln = ln;
	if (!(new->array = malloc(sizeof(int) * ln)))
		error("Error with malloc of array in list\n", 2);
	if (!(new->color = malloc(sizeof(int) * ln)))
		error("Error with malloc of array in list\n", 2);
	ft_fill_array_of_list(new, line, num, s);
	return (new);
}

void			ft_list_add(t_matr *head, t_matr *new)
{
	t_matr *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}