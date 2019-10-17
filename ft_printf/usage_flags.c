/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:20:46 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_flagsfor_signedzero(t_spec *list, char *flagged)
{
	if (list->flag_plus == 1 || list->flag_space == 1)
	{
		if (list->presence_dot == 0)
		{
			flagged = ft_strnew(2);
			flagged[1] = '0';
		}
		else
			flagged = ft_strnew(1);
		flagged[0] = list->flag_plus == 1 ? '+' : ' ';
		list->flag_us++;
	}
	else if ((list->flag_plus == 0 && list->flag_space == 0) &&
			list->presence_dot == 1)
		flagged = ft_strnew(0);
	else
	{
		flagged = ft_strnew(1);
		flagged[0] = '0';
	}
	return (flagged);
}

char				*ft_flag_sign(long long int num, t_spec *list)
{
	char				*flagged;

	if (list->wtf == 1)
		list->precision = list->width;
	flagged = NULL;
	if (num > 0 && (list->flag_plus == 1 || list->flag_space == 1))
	{
		flagged = ft_itoa(-num);
		flagged[0] = list->flag_plus == 1 ? '+' : ' ';
		list->flag_us++;
	}
	else if (num < 0)
	{
		flagged = ft_itoa(num);
		list->flag_us++;
	}
	else if (num == 0)
		return (ft_flagsfor_signedzero(list, flagged));
	else
		flagged = ft_itoa(num);
	return (flagged);
}

char				*ft_fillingflag_hex(char *numb, int size,
										int base, t_spec *list)
{
	char			*flagged;
	size_t			i;
	size_t			j;

	if (base == 16)
	{
		flagged = ft_strnew(ft_strlen(numb) + 2);
		flagged[0] = '0';
		flagged[1] = (size == 0) ? 'x' : 'X';
		i = 2;
	}
	else
	{
		flagged = ft_strnew(ft_strlen(numb) + 1);
		flagged[0] = '0';
		i = 1;
		list->flag_o = 1;
	}
	list->flag_us += i;
	j = 0;
	while (numb[j])
		flagged[i++] = numb[j++];
	free(numb);
	return (flagged);
}

char				*ft_flagsfor_unsignedzero(char *numb, int base,
					t_spec *list)
{
	char			*flagged;

	if (list->flag_hash == 1 && base == 8 && list->presence_dot == 1 &&
													list->precision == 0)
	{
		flagged = ft_strnew(1);
		flagged[0] = '0';
		free(numb);
	}
	else if (list->presence_dot == 1)
	{
		flagged = ft_strnew(0);
		free(numb);
	}
	else
	{
		flagged = ft_strnew(1);
		flagged[0] = '0';
		free(numb);
	}
	return (flagged);
}

char				*ft_flag_unsign(ULL num, t_spec *list,
					char type)
{
	char	*numb;
	int		base;
	int		size;

	size = 0;
	if (type == 'u' || type == 'o' || type == 'U')
		base = type == 'o' ? 8 : 10;
	else
		base = 16;
	if (type == 'X')
		size = 1;
	if (num != 0)
	{
		numb = ft_unsigned_itoa_base(num, base, size);
		if (list->flag_hash == 1 && (base == 16 || base == 8))
			return (ft_fillingflag_hex(numb, size, base, list));
		else
			return (numb);
	}
	else
	{
		numb = ft_unsigned_itoa_base(num, base, size);
		return (ft_flagsfor_unsignedzero(numb, base, list));
	}
}
