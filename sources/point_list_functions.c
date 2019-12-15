/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 23:26:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/04 03:12:16 by ymanilow         ###   ########.fr       */
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

int			ft_fill_color(t_matr *new, char *line, int *check, t_pointers *p)
{
	int j;
	static int i;
	char *s;

	j = 0;
	if (!*check)
		i = 0;
	if (*line == ',')
	{
		s = malloc(sizeof(char *) * 9);
		s[8] = '\0';
		line++;
		while (*line == '0' || *line == 'x')
			s[j++] = *line++;
		while (ft_isdigit(*line) || ft_is_hex(*line))
			s[j++] = *line++;
		new->color[++i] = hex_to_dec(s + 2);
		j++;
		p->color.flag_color = 1;
		free(s);
	}
	else
		new->color[++i] = 0;
	*check += 1;
	return (j);
}

void		ft_fill_array_of_list(t_matr *new, char *line,
							__int128_t num, t_pointers *p)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		if (!ft_isdigit(*line) && *line != '-' && *line != '+')
			continue;
		num = ft_atoi(line);
		new->array[i] = num;
		if (num != new->array[i++])
			ft_error("Overflow of int\n", 2);
		while (ft_isdigit(*line) || *line == '-' || *line == '+')
			line++;
		line += ft_fill_color(new, line, &j, p);
	}
}

t_matr			*ft_list_create(int ln, char *line, t_pointers *point)
{
	t_matr				*new;
	__int128_t			num;

	if (!(new = malloc(sizeof(t_matr))))
		ft_error("Error with malloc of list\n", 2);
	ft_memset(new, 0, sizeof(t_matr));
	new->ln = ln;
	if (!(new->array = malloc(sizeof(int) * ln)))
		ft_error("Error with malloc of array in list\n", 2);
	if (!(new->color = malloc(sizeof(int) * ln)))
		ft_error("Error with malloc of array in list\n", 2);
	ft_fill_array_of_list(new, line, num, point);
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