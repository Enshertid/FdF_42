/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:53:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/17 18:49:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_check_line(t_pointers *point, char *line)
{
	while (*line)
	{
		if (ft_isspace(*line) || ft_isdigit(*line) || *line == '-' ||
		*line == '+')
		{
			if (*line == '-' || *line == '+')
				if (!ft_isdigit(*(line + 1)))
					error("wrong symbol\n", 2);
			line++;
		}
		else
			error("wrong symbol\n", 2);
	}
}

void			ft_pars_line(t_pointers *point, char *line)
{
	int	ln;
	int	i;

	i = 0;
	ln = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
				i++;
		while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
				i++;
		if (i > 0 && ft_isdigit(line[i - 1]))
			ln++;
	}
	if (ln > 0 && !point->matr)
		point->matr = ft_list_create(ln, line);
	else if (ln > 0)
		ft_list_add(point->matr, ft_list_create(ln, line));
}

void			ft_check_size(t_pointers *point)
{
	int			ln_x;
	t_matr		*tmp;
	
	tmp = point->matr;
	ln_x = point->matr->ln;
	if (tmp)
		while (tmp->next)
		{
			if (tmp->ln < ln_x)
				error ("wrong_size\n", 2);
			else
				tmp = tmp->next;
		}
	else
		error ("matrix is empty\n", 2);
}

void			ft_fill_matrix(t_pointers *point)
{
	t_matr		*tmp;
	int			ln;
	int			i;
	
	ln = 0;
	tmp = point->matr;
	while (tmp)
	{
		ln++;
		tmp = tmp->next;
	}
	point->mtrx.array = (int**)malloc(sizeof(int*) * ln);
	i = 0;
	while (i < ln)
		point->mtrx.array[i++] = (int*)malloc(sizeof(int) * point->matr->ln);
	point->mtrx.ln_x = point->matr->ln;
	point->mtrx.ln_y = ln;
	ln = -1;
	tmp = point->matr;
	while (tmp && point->mtrx.array[++ln])
	{
		ft_memcpy(point->mtrx.array[ln], tmp->array, point->mtrx.ln_x * 4);
		tmp = tmp->next;
	}
}

void			ft_parsing(t_pointers *point, int ac, char **str)
{
	int			fd;
	char		*line;

	if (ac != 2)
		error("wrong number of arguments\n", 2);
	fd = open(str[1], O_RDONLY);
	ft_printf("str[1] = %s\n", str[1]);
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_check_line(point, line);
		ft_pars_line(point, line);
		ft_strdel(&line);
	}
	ft_check_size(point);
	ft_fill_matrix(point);
}
