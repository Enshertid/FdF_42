/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:42:48 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_dpow(long double num, int n)
{
	if (!n)
		return (1);
	if (n < 0)
		return (1 / ft_dpow(num, -n));
	if (n & 1)
		return (num * ft_dpow(num, n - 1));
	else
		return (ft_dpow(num * num, n >> 1));
}
