/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:10:54 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mod_sign(t_spec *list, va_list per)
{
	char			num_char;
	short int		num_short;
	long int		num_long;
	long long int	num_long_long;

	if (list->mod == CHAR)
	{
		num_char = (char)va_arg(per, int);
		return (ft_flag_sign(num_char, list));
	}
	else if (list->mod == SHORT)
	{
		num_short = (short int)va_arg(per, int);
		return (ft_flag_sign(num_short, list));
	}
	else if (list->mod == LONG)
	{
		num_long = (long int)va_arg(per, long int);
		return (ft_flag_sign(num_long, list));
	}
	else
	{
		num_long_long = (long long int)va_arg(per, long long int);
		return (ft_flag_sign(num_long_long, list));
	}
}

char	*ft_mod_unsign(t_spec *list, va_list per, char type)
{
	unsigned char				num_char;
	unsigned short int			num_short;
	unsigned long int			num_long;
	unsigned long long int		num_long_long;

	if (list->mod == CHAR)
	{
		num_char = (unsigned char)va_arg(per, unsigned int);
		return (ft_flag_unsign(num_char, list, type));
	}
	else if (list->mod == SHORT)
	{
		num_short = (unsigned short int)va_arg(per, unsigned int);
		return (ft_flag_unsign(num_short, list, type));
	}
	else if (list->mod == LONG)
	{
		num_long = (unsigned long int)va_arg(per, unsigned long int);
		return (ft_flag_unsign(num_long, list, type));
	}
	num_long_long = (unsigned long long int)va_arg(per, unsigned long long int);
	return (ft_flag_unsign(num_long_long, list, type));
}

char	*ft_parswidth(t_spec *list, char *numb)
{
	char	*str_head;
	char	*str;

	str = ft_strnew(list->width);
	if (list->presence_dot == 0 && list->flag_zero == 1 &&
									list->flag_minus == 0)
		ft_memset(str, '0', list->width);
	else
		ft_memset(str, ' ', list->width);
	str_head = str;
	if (ft_strlen(numb) > list->precision && list->flag_minus == 0 &&
										list->presence_dot == 0)
		return (ft_width_noprecision(numb, list, str, str_head));
	else if ((list->presence_dot == 1 && list->flag_minus == 0))
		return (ft_width_with_precision(numb, list, str, str_head));
	else if (list->flag_minus == 1 && list->presence_dot == 0)
		return (ft_right_aligned_without_precision(numb, str, str_head));
	else if (list->flag_minus == 1 && list->presence_dot == 1)
		return (ft_right_aligned_with_precision(numb, str, list, str_head));
	else
		return (str);
}

char	*ft_digitals(const char **str, t_spec *list, va_list per)
{
	char	*numb;

	if (**str == 'U')
		list->mod = LONG_LONG;
	if (list->mod != DEFAULT && (**str == 'd' || **str == 'i'))
		numb = (ft_mod_sign(list, per));
	else if (list->mod != DEFAULT && (**str == 'o' ||
	**str == 'x' || **str == 'X' || **str == 'u' || **str == 'U'))
		numb = (ft_mod_unsign(list, per, **str));
	else if (**str == 'd' || **str == 'i')
		numb = ft_flag_sign(va_arg(per, int), list);
	else
		numb = ft_flag_unsign(va_arg(per, unsigned int), list, **str);
	(*str)++;
	if (list->precision >= list->width &&
					list->precision + list->flag_us >= ft_strlen(numb))
		return (ft_output_only_precision(numb, list));
	else if (ft_strlen(numb) - list->flag_us > list->precision &&
		ft_strlen(numb) > list->width)
		return (numb);
	else if (list->width > list->precision)
		return (ft_parswidth(list, numb));
	else
		return (numb);
}

char	*ft_type_definition(const char **str,
		t_spec *list, va_list per, t_buff *buff)
{
	if (**str == 'd' || **str == 'i' || **str == 'u' || **str == 'o' ||
		**str == 'x' || **str == 'X' || **str == 'U')
		return (ft_digitals(str, list, per));
	else if (**str == 'c')
		return (ft_signed_char(str, list, va_arg(per, int), buff));
	else if (**str == '%')
		return (ft_signed_char(str, list, '%', buff));
	else if (**str == 's')
		return (ft_string_output(str, list, va_arg(per, char*)));
	else if (**str == 'p')
		return (ft_pointer_output(str, list, va_arg(per, ptrdiff_t)));
	else if (**str == 'f')
		return (get_double(str, per, list));
	else if (**str == 'b')
		return (get_binary(va_arg(per, char*), list));
	else
		return (ft_strdup(""));
}
