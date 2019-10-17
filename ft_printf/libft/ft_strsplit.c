/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:27:18 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(const char *str, char c)
{
	register size_t count;

	count = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || !*(str + 1)))
			++count;
		++str;
	}
	return (count);
}

static const char	*word_from_str(const char *str, char c, size_t *len)
{
	register size_t size;

	while (*str == c)
		++str;
	size = 0;
	while (str[size] != c && str[size])
		++size;
	*len = size;
	return (str);
}

char				**ft_strsplit(const char *str, char c)
{
	char	**arr;
	size_t	iter;
	size_t	words;
	size_t	word_len;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	if (!(arr = (char**)malloc((words + 1) * sizeof(char*))))
		return (NULL);
	iter = 0;
	while ((str = word_from_str(str, c, &word_len)) && *str)
	{
		if (!(arr[iter] = (char*)malloc(word_len + 1)))
		{
			ft_arrdel((void***)&arr);
			return (NULL);
		}
		ft_strncpy(arr[iter], str, word_len);
		arr[iter][word_len] = '\0';
		str += word_len;
		++iter;
	}
	arr[words] = NULL;
	return (arr);
}
