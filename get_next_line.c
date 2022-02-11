/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:23 by mraspors          #+#    #+#             */
/*   Updated: 2022/02/08 21:21:35 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read(fd, &s[i], BUFFER_SIZE)

char	*get_next_line(int fd)
{
	char	*result_s;
	char	s[50000];
	int		i;

	i = 0;
	result_s = NULL;
	if (BUFFER_SIZE < 1 || fd == -1)
		return (NULL);
	while (read(fd, &s[i], BUFFER_SIZE) != 0)
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	s[i + 1] = '\0';
	result_s = (char *)malloc(ft_strlen(s) * sizeof(char));
	ft_strlcpy(result_s, s, ft_strlen(s) - 1);
	return (result_s);
}

/*int main ()
{
    	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("string: %s.\n", s);
	return 0;
}*/