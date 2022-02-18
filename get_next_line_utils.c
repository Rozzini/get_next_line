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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


int	ft_strchr(char *s)
{
	char	*str;
	size_t		i;

	i = 0;
	str = (char *)s;
	while (i < (ft_strlen(s) - 1))
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == 0 && src == 0) || n == 0)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_l;
	int		s2_l;

	if (!s2)
		return (NULL);
	if (!s1 && s2)
		s1_l = 0;
	else
		s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1, s1_l);
	ft_strcpy(&str[s1_l], s2, s2_l);
	str[s1_l + s2_l] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);
}