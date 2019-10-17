/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:18:45 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	char	cnum[11];
	size_t	iter;

	if (num == MIN_INT)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	iter = 0;
	if (num < 0)
	{
		cnum[iter++] = '-';
		num = -num;
	}
	while (num)
	{
		cnum[iter] = num % 10 + '0';
		num /= 10;
		++iter;
	}
	cnum[iter] = '\0';
	ft_strrev(cnum + (cnum[0] == '-'));
	ft_putstr_fd(cnum, fd);
}
