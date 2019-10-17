/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:20:31 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_output_only_precision_pointer(char *numb, t_spec *list)
{
	char				*str;
	char				*str_head;
	char				*numb_head;

	str = ft_strnew(list->precision - ft_strlen(numb) + list->flag_o);
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
	ft_memset(str, '0', list->precision - list->flag_o);
	str += (ft_strlen(str) - ft_strlen(numb));
	while (*str && *numb)
		*str++ = *numb++;
	free(numb_head);
	return (str_head);
}

char	*ft_pointer_output(const char **str, t_spec *list, ptrdiff_t per)
{
	char *numb;

	list->mod = DEFAULT;
	list->flag_hash = 1;
	if (per == 0)
		numb = ft_strdup("0x0");
	else
		numb = ft_flag_unsign(per, list, **str);
	(*str)++;
	if (list->precision >= list->width &&
		list->precision + list->flag_us >= ft_strlen(numb))
		return (ft_output_only_precision_pointer(numb, list));
	else if (list->width == 0 && list->precision == 0 &&
	list->presence_dot == 1 && per == 0)
		return (ft_strdup("0x"));
	else if (ft_strlen(numb) - list->flag_us > list->precision &&
			ft_strlen(numb) > list->width)
		return (numb);
	else if (list->width > list->precision)
		return (ft_parswidth(list, numb));
	else
		return (numb);
}
