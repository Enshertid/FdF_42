/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:28:29 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_othercolor(const char **str, t_spec *list)
{
	if (**str == 'b')
		list->color = BLUE;
	else if (**str == 'P')
		list->color = PURPLE;
	else if (**str == 'p')
		list->color = PINK;
	else if (**str == 'O')
		list->color = ORANGE;
	else if (**str == 'g')
		list->color = GREY;
	else if (**str == 'T')
		list->color = TURQUOISE;
}

void			ft_check_color(const char **str, t_spec *list)
{
	if (**str == 'k')
	{
		(*str)++;
		if (**str == 'W')
			list->color = WHITE;
		else if (**str == 'B')
			list->color = BLACK;
		else if (**str == 'R')
			list->color = RED;
		else if (**str == 'Y')
			list->color = YELLOW;
		else if (**str == 'G')
			list->color = GREEN;
		else
			ft_check_othercolor(str, list);
		(*str) += (**str == 'W' || **str == 'B' || **str == 'R' ||
				**str == 'Y' || **str == 'G' || **str == 'P' || **str == 'p' ||
				**str == 'O' || **str == 'T' || **str == 'g' || **str == 'b');
	}
}

void			ft_end_color_to_buff(t_buff *buff, t_spec *list)
{
	char		*str;
	int			j;

	str = ft_strdup("\e[0m");
	j = 0;
	if (buff->i + 5 > BUFF_SIZE && list->fd > 0)
	{
		write(list->fd, buff->buff, buff->i);
		write(list->fd, str, 5);
		buff->return_value += 5;
		buff->i = 0;
		free(str);
	}
	else if (list->fd > 0)
	{
		while (j < 4 && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str[j++];
		free(str);
	}
}

char			*ft_create_color(t_spec *list)
{
	char	*str;

	if (list->color == WHITE)
		str = ft_strdup("\e[38;5;255m");
	else if (list->color == BLACK)
		str = ft_strdup("\e[38;5;232m");
	else if (list->color == RED)
		str = ft_strdup("\e[38;5;001m");
	else if (list->color == GREEN)
		str = ft_strdup("\e[38;5;040m");
	else if (list->color == YELLOW)
		str = ft_strdup("\e[38;5;011m");
	else if (list->color == BLUE)
		str = ft_strdup("\e[38;5;075m");
	else if (list->color == PURPLE)
		str = ft_strdup("\e[38;5;105m");
	else if (list->color == PINK)
		str = ft_strdup("\e[38;5;013m");
	else if (list->color == ORANGE)
		str = ft_strdup("\e[38;5;130m");
	else if (list->color == GREY)
		str = ft_strdup("\e[38;5;007m");
	else
		str = ft_strdup("\e[38;5;123m");
	return (str);
}

void			ft_add_color_to_buff(t_buff *buff, t_spec *list)
{
	int		j;
	char	*str;

	str = ft_create_color(list);
	j = 0;
	if (buff->i + 12 > BUFF_SIZE && list->fd > 0)
	{
		write(list->fd, buff->buff, buff->i);
		write(list->fd, str, 12);
		buff->return_value += 12;
		buff->i = 0;
		free(str);
	}
	else if (list->fd > 0)
	{
		while (j < 11 && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str[j++];
		free(str);
	}
}
