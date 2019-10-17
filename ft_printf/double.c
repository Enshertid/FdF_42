/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:59:11 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_integer_part(char *str, t_double num, t_spec *list)
{
	*(str - DBL_SIZE + 2) = (num.sign ? '-' : 0);
	if (!*(str - DBL_SIZE + 2) && list->flag_space)
		*(str - DBL_SIZE + 2) = ' ';
	if (*(str - DBL_SIZE + 2) != '-' && list->flag_plus)
		*(str - DBL_SIZE + 2) = '+';
	if (num.exp < 1)
		ft_itoa_buf(0, str, 10, 0);
	else
	{
		num.mantissa >>= (num.exp < 64 ? 64 - num.exp : 0);
		ft_itoa_buf(num.mantissa, str - sizeof_num(num.mantissa, 10) + 1,
					10, 0);
	}
	if (num.exp < 65)
		return (ft_memrchr(str, 0, INT_PART) + 1);
	num.exp -= 64;
	while (num.exp)
	{
		mult(str, num.exp > 31 ? 4294967296 : 2);
		num.exp -= (num.exp > 31 ? 32 : 1);
	}
	return (ft_memrchr(str, 0, INT_PART) + 1);
}

void	get_fract_part(char *str, t_double num)
{
	int		iter;
	char	plus[DBL_SIZE];

	*str++ = '.';
	if (num.exp > 63 || !num.mantissa ||
		(num.exp > 0 && !((num.mantissa <<= num.exp))))
		return ;
	ft_memset(plus, 0, DBL_SIZE);
	plus[DBL_SIZE - 2] = '5';
	iter = 1;
	while (num.exp++ < 0)
	{
		++iter;
		mult(plus + DBL_SIZE - 2, 5);
	}
	evaluate_mantissa(str, plus, num.mantissa, iter);
}

char	*double_to_str(long double d, t_spec *format)
{
	char		*str;
	t_double	num;
	size_t		len;
	char		*iter;

	parse_double(&d, &num);
	if (num.is_inf || num.is_nan)
	{
		if (num.sign)
			return (ft_strjoin("-", num.is_inf ? "inf" : "nan"));
		if (format->flag_plus)
			return (ft_strjoin("+", num.is_inf ? "inf" : "nan"));
		if (format->flag_space)
			return (ft_strjoin(" ", num.is_inf ? "inf" : "nan"));
		return (ft_strjoin("", num.is_inf ? "inf" : "nan"));
	}
	str = (char*)malloc(DBL_SIZE);
	ft_memset(str, 0, DBL_SIZE);
	iter = get_integer_part(str + DBL_SIZE - 2, num, format);
	len = ft_strlen(iter);
	ft_memcpy(str + 2, iter, len);
	ft_memset(iter, 0, len);
	get_fract_part(str + 2 + len, num);
	str = set_precision(str, format);
	return (str);
}

char	*get_double(const char **str, va_list pre, t_spec *list)
{
	char		*str_out;
	char		*iter;
	char		*iter1;
	size_t		double_len;

	(*str)++;
	if (list->mod == LONG_DOUBLE)
		str_out = double_to_str(va_arg(pre, long double), list);
	else
		str_out = double_to_str(va_arg(pre, double), list);
	iter = ft_memnchr(str_out, 0, 3);
	double_len = ft_strlen(iter);
	if (list->width > double_len)
		return (set_width(str_out, iter, list, double_len));
	iter1 = str_out;
	while (*(iter))
		*(iter1++) = *(iter++);
	*iter1 = *iter;
	return (str_out);
}
