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

char	*ft_rewrite(char *result, char *s)
{
	char	*temp;
	size_t	len_tmp;
	size_t	len_s;


	if (result == NULL)
	{
		len_s = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (len_s));
		ft_strlcpy(result, s, len_s);
		free(s);
	}
	else
	{
		len_tmp = ft_strlen(result);
		temp = (char *)malloc(sizeof(char) * len_tmp);
		ft_strlcpy(temp, result, len_tmp);
		free(result);
		len_s = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (len_s + len_tmp));
		ft_strlcpy(result, temp, len_tmp);
		ft_strlcpy(&result[len_tmp], s, len_s);
		free(s);
	}
	return (result);
}

char	*save(char *buf, char *result, char *s, char *p)
{
	char	*temp;
	size_t	len_temp;
	size_t	len_sp;

	len_temp = ft_strlen(p);
	buf = (char *)malloc(sizeof(char) * len_temp);
	ft_strlcpy(buf, p, len_temp);
	p[0] = '\0';
	result = ft_rewrite(result, s);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*result;
	char		*s;
	char		*p;
	size_t		i;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = NULL;
	printf("\nBuf: %s\n", buf);
	if (buf != NULL)
	{
		i = ft_strlen(buf);
		s = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		ft_strlcpy(s, buf, i);
		free(buf);
		p = ft_strchr(s, BUFFER_SIZE);
		if (p == NULL)
		{
			result = (char *)malloc(sizeof(char) * i);
			ft_strlcpy(result, s, i + 1);
			free(s);
		}
		else
		{
			save(buf, result, s, p);
			return (result);
		}
	}
	s = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	s[BUFFER_SIZE + 1] = '\0';
	while (read(fd, s, BUFFER_SIZE) != 0)
	{
		p = ft_strchr(s, BUFFER_SIZE);
		if (p != NULL)
			break;
		else
			result = ft_rewrite(result, s);
		s = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		s[BUFFER_SIZE + 1] = '\0';	
	}
	save(buf, result, s, p);
	return (result);
}

//printf("\n\ncheckpoint 1\n\n");

int main ()
{
    	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);

	printf("\noutput1\n");
	s = get_next_line(fd);
	printf("%s_\n", s);

	printf("\noutput2\n");
	s = get_next_line(fd);
	printf("%s_\n", s);

	printf("\noutput3\n");
	s = get_next_line(fd);
	printf("%s_\n", s);
	return 0;
}