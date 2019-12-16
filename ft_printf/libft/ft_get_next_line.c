/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:28:30 by ymanilow          #+#    #+#             */
/*   Updated: 2019/12/16 20:28:16 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char		*ft_str_out_and_del(char *s, char **line)
{
	char		*s1;
	char		*s2;
	int			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	s1 = ft_strsub(s, 0, i);
	*line = s1;
	s2 = s;
	s = ft_strsub(s2, i + 1, ft_strlen(s2) - i);
	ft_strdel(&s2);
	return (s);
}

char		*ft_read_out(char *s, int fd)
{
	int			ret;
	char		*s1;
	char		buff[GNL_BUFF_SIZE + 1];

	while ((ret = read(fd, buff, GNL_BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s1 = s;
		s = ft_strjoin(s, buff);
		ft_strdel(&s1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (s);
}

int			ft_get_next_line(int fd, char **line)
{
	static char			*s[10000];
	char				*s1;

	if (fd < 0 || fd > 10000 || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	s[fd] = ft_read_out(s[fd], fd);
	if (ft_strchr(s[fd], '\n'))
	{
		s[fd] = ft_str_out_and_del(s[fd], line);
		return (1);
	}
	else if (s[fd][0])
	{
		s1 = ft_strdup(s[fd]);
		*line = s1;
		ft_strdel(&s[fd]);
		return (1);
	}
	return (0);
}
