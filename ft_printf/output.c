/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:02:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_str_out(char *str_out, t_buff *buff, t_spec *list)
{
	int j;

	j = 0;
	if (list->color != USUAL)
		ft_add_color_to_buff(buff, list);
	if (ft_strlen(str_out) + buff->i > BUFF_SIZE && list->fd > 0)
	{
		write(list->fd, buff->buff, buff->i);
		write(list->fd, str_out, ft_strlen(str_out));
		buff->return_value += buff->i + ft_strlen(str_out);
		buff->i = 0;
		free(str_out);
	}
	else if (list->fd > 0)
	{
		while (str_out[j] && buff->i < BUFF_SIZE)
			buff->buff[buff->i++] = str_out[j++];
		free(str_out);
	}
	if (list->color != USUAL)
		ft_end_color_to_buff(buff, list);
}

void				ft_cleanbuff_andout(t_spec *list, t_buff *buff)
{
	buff->return_value += buff->i;
	write(list->fd, buff->buff, buff->i);
	if (buff->i == BUFF_SIZE)
		buff->i = 0;
	buff->i = 0;
	ft_list_clear(list);
}
