/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:57 by mraspors          #+#    #+#             */
/*   Updated: 2022/02/08 21:16:01 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	if (dstsize == 0)
	{
		dst = NULL;
		return (0);
	}
	i = 0;
	src_len = (size_t)ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize)
		{
			if (src[i] != '\0')
				dst[i] = src[i];
			else
				break ;
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(const char *s, int buf_size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (i < buf_size)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}