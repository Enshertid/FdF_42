/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:20:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stringonly_width(t_spec *list, char *str_arg,
										char *str_head, char *str_out)
{
	str_out = ft_strnew(list->width);
	str_head = str_out;
	if (list->flag_zero == 1 && list->flag_minus == 0)
		ft_memset(str_out, '0', list->width);
	else
		ft_memset(str_out, ' ', list->width);
	if (list->flag_minus == 0)
		str_out += list->width - ft_strlen(str_arg);
	while (*str_arg && *str_out)
		*str_out++ = *str_arg++;
	return (str_head);
}

char	*ft_stringonly_precision(t_spec *list, char *str_arg,
											char *str_head, char *str_out)
{
	size_t lenght;

	lenght = ft_strlen(str_arg);
	if (list->precision <= lenght)
		lenght = list->precision;
	str_out = ft_strnew(lenght);
	str_head = str_out;
	ft_memset(str_out, ' ', lenght);
	while (*str_arg && *str_out)
		*str_out++ = *str_arg++;
	return (str_head);
}

char	*ft_string_all_width(t_spec *list, char *str_arg,
										char *str_head, char *str_out)
{
	size_t lenght;

	lenght = ft_strlen(str_arg);
	str_out = ft_strnew(list->width);
	if (list->flag_zero == 1 && list->flag_minus == 0)
		ft_memset(str_out, '0', list->width);
	else
		ft_memset(str_out, ' ', list->width);
	str_head = str_out;
	if (list->flag_minus == 0 && list->precision > lenght)
		str_out += list->width - lenght;
	else if (list->flag_minus == 0)
		str_out += list->width - list->precision;
	if (list->precision >= lenght)
		while (*str_out && *str_arg)
			*str_out++ = *str_arg++;
	else
		while (*str_out && *str_arg && list->precision != 0)
		{
			*str_out++ = *str_arg++;
			list->precision--;
		}
	return (str_head);
}

char	*ft_string_all(t_spec *list, char *str_arg,
									char *str_head, char *str_out)
{
	size_t lenght;

	lenght = ft_strlen(str_arg);
	if (list->width > list->precision)
		return (ft_string_all_width(list, str_arg, str_head, str_out));
	else
	{
		if (list->width >= lenght)
			lenght = list->width;
		else if (list->precision <= lenght)
			lenght = list->precision;
		str_out = ft_strnew(lenght);
		if (list->flag_zero == 1 && list->flag_minus == 0)
			ft_memset(str_out, '0', lenght);
		else
			ft_memset(str_out, ' ', lenght);
		str_head = str_out;
		lenght = ft_strlen(str_arg);
		if (list->width >= lenght && list->flag_minus == 0)
			str_out += list->width - lenght;
	}
	while (*str_out && *str_arg)
		*str_out++ = *str_arg++;
	return (str_head);
}

char	*ft_string_output(const char **str, t_spec *list,
									char *str_arg)
{
	char *str_out;
	char *str_head;

	str_out = NULL;
	str_head = str_out;
	if (!str_arg)
		return (ft_string_output(str, list, "(null)"));
	(*str)++;
	if (list->presence_dot == 0 && list->width > ft_strlen(str_arg))
		return (ft_stringonly_width(list, str_arg, str_head, str_out));
	else if (list->presence_dot == 1 && list->width == 0)
		return (ft_stringonly_precision(list, str_arg, str_head, str_out));
	else if (list->presence_dot == 1 && list->width != 0 &&
				list->precision != 0)
		return (ft_string_all(list, str_arg, str_head, str_out));
	else if (list->presence_dot == 1 && list->precision == 0)
		return (ft_memset(ft_strnew(list->width), ' ', list->width));
	else
	{
		str_out = ft_strnew(ft_strlen(str_arg));
		str_head = ft_strcpy(str_out, str_arg);
		return (str_head);
	}
}
