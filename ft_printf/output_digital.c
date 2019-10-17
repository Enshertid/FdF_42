/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_digital.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:20:06 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_width_noprecision(char *numb, t_spec *list,
					char *str, char *str_head)
{
	char				*numb_head;

	numb_head = numb;
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X') &&
				(list->flag_hash == 0 || list->flag_zero == 1))
	{
		*str++ = *numb++;
		*str++ = *numb++;
	}
	if ((numb[0] == '+' || numb[0] == '-' || numb[0] == ' ') &&
											list->flag_zero == 1)
		*str++ = *numb++;
	str += (ft_strlen(str) - ft_strlen(numb));
	while (*str && *numb)
		*str++ = *numb++;
	free(numb_head);
	return (str_head);
}

char					*ft_width_with_precision(char *numb,
					t_spec *list, char *str, char *str_head)
{
	char				*numb_head;
	int					start_of_numb;
	int					iter;

	numb_head = numb;
	iter = (ft_strlen(numb) - list->flag_us <= list->precision) ?
			(ft_strlen(str) - list->precision - list->flag_us + list->flag_o) :
			(ft_strlen(str) - ft_strlen(numb));
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X'))
	{
		str[iter++] = numb[0];
		str[iter++] = numb[1];
		numb += 2;
	}
	else if (numb[0] == '+' || numb[0] == '-' || numb[0] == ' ' ||
													numb[0] == '0')
		str[iter++] = *numb++;
	start_of_numb = ft_strlen(str) - ft_strlen(numb);
	while (iter != start_of_numb)
		str[iter++] = '0';
	while (str[iter] && *numb)
		str[iter++] = *numb++;
	free(numb_head);
	return (str_head);
}

char					*ft_right_aligned_without_precision(char *numb,
					char *str, char *str_head)
{
	char				*numb_head;

	numb_head = numb;
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X'))
	{
		*str++ = *numb++;
		*str++ = *numb++;
	}
	else if (numb[0] == '+' || numb[0] == '-' ||
				numb[0] == ' ' || numb[0] == '0')
		*str++ = *numb++;
	while (*numb && *str)
		*str++ = *numb++;
	free(numb_head);
	return (str_head);
}

char					*ft_right_aligned_with_precision(char *numb,
					char *str, t_spec *list, char *str_head)
{
	char				*numb_head;
	int					iter;
	int					start_of_numb;

	numb_head = numb;
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X'))
	{
		*str++ = *numb++;
		*str++ = *numb++;
	}
	else if (numb[0] == '+' || numb[0] == '-' ||
				numb[0] == ' ' || numb[0] == '0')
		*str++ = *numb++;
	iter = 0;
	start_of_numb = (list->precision >= ft_strlen(numb)) ?
			list->precision - ft_strlen(numb) - list->flag_o : 0;
	while (iter != start_of_numb)
		str[iter++] = '0';
	while (str[iter] && *numb)
		str[iter++] = *numb++;
	free(numb_head);
	return (str_head);
}

char					*ft_output_only_precision(char *numb, t_spec *list)
{
	char				*str;
	char				*str_head;
	char				*numb_head;

	str = ft_strnew(list->precision + list->flag_us);
	str_head = str;
	numb_head = numb;
	if (numb[0] == '0' && (numb[1] == 'x' || numb[1] == 'X'))
	{
		*str++ = *numb++;
		*str++ = *numb++;
	}
	else if (numb[0] == '+' || numb[0] == '-' ||
				numb[0] == ' ' || numb[0] == '0')
		*str++ = *numb++;
	if (ft_strlen(numb) >= list->precision)
		ft_memset(str, '0', list->precision);
	else
		ft_memset(str, '0', list->precision - list->flag_o);
	str += (ft_strlen(str) - ft_strlen(numb));
	while (*str && *numb)
		*str++ = *numb++;
	free(numb_head);
	return (str_head);
}
