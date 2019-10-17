/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:26:29 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_double(long double *d, t_double *num)
{
	ft_memset(num, 0, sizeof(t_double));
	*(char*)&(num->exp) = *((char*)d + 8);
	*((char*)&(num->exp) + 1) = *((char*)d + 9);
	if (num->exp & 32768)
	{
		num->sign = 1;
		num->exp &= 32767;
	}
	else
		num->sign = 0;
	num->mantissa = *((ULL*)d);
	num->exp -= 16382;
	if (*d != *d)
		num->is_nan = 1;
	else if (*d && *d == (*d * 10))
		num->is_inf = 1;
}

void	evaluate_mantissa(char *str, char *plus, ULL mantissa, int iter)
{
	char	*plus_head;

	plus_head = plus + DBL_SIZE - 2;
	while (mantissa)
	{
		if (mantissa >> 63)
		{
			plus_head = ft_memrchr(plus_head, 0, DBL_SIZE) + 1;
			add(str + offset(iter) + ft_strlen(plus_head) - 1,
				plus + DBL_SIZE - 2);
		}
		if ((mantissa <<= 1))
			mult(plus + DBL_SIZE - 2, 5);
		++iter;
	}
	while (!*str)
		*str++ = '0';
}

char	*set_precision(char *str, t_spec *format)
{
	char	*dot;
	size_t	len;

	if (!format->presence_dot)
		format->precision = 6;
	if (format->precision > 214748199)
		format->precision = 214748199;
	format->precision = (format->precision > INT_MAX ?
							INT_MAX : format->precision);
	dot = ft_memchr(str, '.', DBL_SIZE);
	len = ft_strlen(dot + 1);
	if (dot - str + format->precision + 1 > DBL_SIZE)
		format->precision = DBL_SIZE - (dot - str) + 1;
	if (format->precision > len)
		ft_memset(dot + 1 + len, '0', format->precision - len);
	else
	{
		if (dot[format->precision + 1] > '4')
			add(dot + format->precision, "\0001" + 1);
		dot[!format->flag_hash && format->presence_dot && !format->precision ?
			0 : format->precision + 1] = '\0';
	}
	if (!str[1] && str[0])
		ft_swap(str, str + 1, 1);
	return (str);
}

char	*set_width(char *str, char *iter, t_spec *list, size_t double_len)
{
	char	*new_str;
	size_t	pos;

	list->width = (list->width > 20000 ? 20000 : list->width) - double_len;
	new_str = (char*)malloc(list->width + double_len + 1);
	pos = 0;
	if (!list->flag_minus && list->flag_zero && ft_isdigit(*(str + 2)) &&
												!ft_isdigit(*iter))
		new_str[pos++] = *(iter++);
	if (!list->flag_minus)
		ft_memset(new_str + (pos += list->width) - list->width,
					list->flag_zero && ft_isdigit(*(str + 2)) ?
				'0' : ' ', list->width);
	if (!list->flag_minus && !list->flag_zero && !ft_isdigit(*iter))
		new_str[pos++] = *(iter++);
	ft_memcpy(new_str + pos, iter, double_len);
	pos += double_len;
	if (list->flag_minus)
	{
		ft_memset(new_str + pos, ' ', list->width);
		pos += list->width;
	}
	new_str[pos] = '\0';
	free(str);
	return (new_str);
}
