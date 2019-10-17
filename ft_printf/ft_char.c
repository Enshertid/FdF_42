/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:59:05 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_charzero(t_spec *list, char *str_out, t_buff *buff)
{
	if (list->width != 0 && list->flag_minus == 0)
	{
		str_out = ft_strnew(list->width - 1);
		if (list->flag_zero == 1)
			ft_memset(str_out, '0', list->width - 1);
		else
			ft_memset(str_out, ' ', list->width - 1);
		ft_str_out(str_out, buff, list);
		str_out = ft_strnew(0);
	}
	else if (list->width != 0 && list->flag_minus == 1)
	{
		str_out = ft_strnew(list->width - 1);
		ft_memset(str_out, ' ', list->width - 1);
	}
	else
		str_out = ft_strnew(list->width);
	buff->return_value += 1;
	ft_cleanbuff_andout(list, buff);
	write(1, "\0", 1);
	return (str_out);
}

char	*ft_charnotzero(t_spec *list, char *str_out, char symbol)
{
	str_out = ft_strnew(list->width);
	if (list->flag_zero == 1 && list->flag_minus == 0)
	{
		ft_memset(str_out, '0', list->width);
		str_out[list->width - 1] = symbol;
	}
	else
	{
		ft_memset(str_out, ' ', list->width);
		if (list->flag_minus == 1)
			str_out[0] = symbol;
		else
			str_out[list->width - 1] = symbol;
	}
	return (str_out);
}

char	*ft_signed_char(const char **str,
						t_spec *list, char symbol, t_buff *buff)
{
	char			*str_out;

	str_out = NULL;
	ft_cleaningflags_char(list);
	(*str)++;
	if (list->width != 0 && symbol != 0)
		return (ft_charnotzero(list, str_out, symbol));
	else if (symbol != 0)
	{
		str_out = ft_strnew(1);
		str_out[0] = symbol;
	}
	else
		return (ft_charzero(list, str_out, buff));
	return (str_out);
}
