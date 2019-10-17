/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filling_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:17:14 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_check_flags(const char **str, t_spec *list)
{
	while (**str == '+' || **str == '-' || **str == '#' ||
		**str == ' ' || (**str == '0' && list->flag_zero == 0))
	{
		if (**str == '-')
			list->flag_minus = 1;
		else if (**str == '+')
			list->flag_plus = 1;
		else if (**str == ' ')
			list->flag_space = 1;
		else if (**str == '0')
			list->flag_zero = 1;
		else if (**str == '#')
			list->flag_hash = 1;
		(*str)++;
	}
}

void				ft_check_precision(const char **str,
												t_spec *list, va_list per)
{
	long int precision;

	if (**str == '.')
	{
		precision = ft_atoi(++(*str));
		list->presence_dot = 1;
		if (**str == '*')
		{
			precision = va_arg(per, int);
			(*str)++;
		}
		if (precision >= 0)
			list->precision = precision;
		else
		{
			list->flag_minus = 1;
			list->precision = -precision;
			list->wtf = 1;
		}
	}
}

void				ft_check_width(const char **str,
												t_spec *list, va_list per)
{
	long int			width;

	if (**str == '*')
	{
		width = va_arg(per, int);
		(*str)++;
		if (width >= 0)
			list->width = width;
		else
		{
			list->flag_minus = 1;
			list->width = width * -1;
		}
		if (ft_isdigit(**str))
		{
			width = ft_atoi(*str);
			list->width = width;
		}
	}
	else
		list->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	ft_check_precision(str, list, per);
}

void				ft_check_modificate(const char **str, t_spec *list)
{
	if (**str == 'h')
	{
		if (*(++*str) == 'h')
			list->mod = CHAR;
		else
			list->mod = SHORT;
	}
	else if (**str == 'l')
	{
		if (*(++*str) == 'l')
			list->mod = LONG_LONG;
		else
			list->mod = LONG;
	}
	else if (**str == 'L')
		list->mod = LONG_DOUBLE;
	*str += (**str == 'h' || **str == 'l' || **str == 'L');
}
