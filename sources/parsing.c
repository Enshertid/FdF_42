/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:53:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 19:01:16 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_check_line(t_pointers *point, char *line)
{
	while (*line)
	{
		if (ft_isspace(*line) || ft_isdigit(*line) || *line == '-' ||
		*line == '+' || *line != ',' || *line != 'x' || !ft_is_hex(*line))
		{
			if ((*line == '-' || *line == '+') && (!ft_isdigit(*(line + 1))))
					ft_error("wrong symbol\n", 2);
			else if (*line == 'x' && *(line - 1) != '0' &&
					(ft_isdigit(*(line + 1)) || !ft_is_hex(*(line + 1))))
				ft_error ("wrong symbol\n", 2);
			line++;
		}
		else
			ft_error("wrong symbol\n", 2);
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
		if (line[i] == ',')
			while (ft_is_hex(line[i]) || ft_isdigit(line[i]) || line[i] == 'x' || line[i] == ',')
				i++;
	}
	if (ln > 0 && !point->matr)
		point->matr = ft_list_create(ln, line, point);
	else if (ln > 0)
		ft_list_add(point->matr, ft_list_create(ln, line, point));
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
				ft_error ("wrong_size\n", 2);
			else
				tmp = tmp->next;
		}
	else
		ft_error ("matrix is empty\n", 2);
}

void			ft_fill_matrx(t_pointers *point, t_mtrx *mtrx)
{
	t_matr		*tmp;
	int			ln;

	tmp = point->matr;
	ln = -1;
	while (tmp && mtrx->array[++ln])
	{
		ft_memcpy(mtrx->array[ln], tmp->array, mtrx->ln_x * 4);
		tmp = tmp->next;
	}
	ln = -1;
	tmp = point->matr;
	while (tmp && mtrx->color[++ln])
	{
		ft_memcpy(mtrx->color[ln], tmp->color, mtrx->ln_x * 4);
		tmp = tmp->next;
	}
}

void			 ft_copy_matrix(t_mtrx *mtrx, t_pointers *point)
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
	mtrx->array = (int**)malloc(sizeof(int*) * ln);
	mtrx->color = (int**)malloc(sizeof(int*) * ln);
	i = 0;
	while (i < ln)
		mtrx->array[i++] = (int*)malloc(sizeof(int) * point->matr->ln);
	i = 0;
	while(i < ln)
		mtrx->color[i++] = (int*)malloc(sizeof(int) * point->matr->ln);
	mtrx->ln_x = point->matr->ln;
	mtrx->ln_y = ln;
	ft_fill_matrx(point, mtrx);
}

void			ft_parsing(t_pointers *point, int ac, char **str)
{
	int			fd;
	char		*line;
	const char *aaa = "/Users/ymanilow/curcus42/fdf/test_maps/julia.fdf";

//	if (ac != 2)
//		ft_error("wrong number of arguments\n", 2);
	if (ac != 2)
		fd = open(aaa, O_RDONLY);
	else
		fd = open(str[1], O_RDONLY);
	if (fd < 0)
		ft_error ("wrong file\n", 2);
	ft_printf("str[1] = %s\n", str[1]);
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_check_line(point, line);
		ft_pars_line(point, line);
		ft_strdel(&line);
	}
	ft_check_size(point);
	ft_copy_matrix(&point->mtrx, point);
	point->mod.flag_first = TRUE;
}
