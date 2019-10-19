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
		if (ft_isspace(line[i]))
			while (ft_isspace(line[i]))
				i++;
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
			while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
				i++;
		if (i > 0 && ft_isdigit(line[i - 1]))
			ln++;
	}
	if (ln > 0 && !point->dot)
		point->dot = ft_list_create(ln, line);
	else if (ln > 0)
		ft_list_add(point->dot, ft_list_create(ln, line));
}

void			ft_parsing(t_pointers *point, int ac, char **str)
{
	int			fd;
	char		*line;
	t_dot		*tmp;

	if (ac != 3)
		error("wrong number of arguments\n", 2);
	fd = open("/Users/ymanilow/curcus42/fdf/file.txt", O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_check_line(point, line);
		ft_pars_line(point, line);
		ft_strdel(&line);
	}
	tmp = point->dot;
	if (tmp)
		while (tmp->next)
		{
			if (tmp->ln != tmp->next->ln)
				error("Lenght of matrix's are not the same\n", 2);
			tmp = tmp->next;
		}
	else
		error("matrix is empty\n", 0);
}
