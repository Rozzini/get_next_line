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

char	*fill_buf(char *buf)
{
	int	loc;
	char	*result;

	result = NULL;
	loc = ft_strchr(buf);
	if (loc == (int)(ft_strlen(buf) - 1))
	{
		free (buf);
		return (NULL);
	}
	result = ft_strjoin(result, &buf[loc + 1]);
	free(buf);
	return (result);
}

char	*create_result(char *buf)
{
	int	loc;
	char	c;
	char	*result;

	result = NULL;
	loc = ft_strchr(buf);
	if (buf[loc] == '\n')
		loc++;
	c = buf[loc];
	buf[loc] = '\0';
	result =  ft_strjoin(result, buf);
	buf[loc] = c;
	return (result);
}
char	*ft_read(int fd, char *buf)
{
	char	*s;
	int	read_c;
	int	loc;

	while(1)
	{
		s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_c = read(fd, s, BUFFER_SIZE);
		if (read_c <= 0)
			break ;
		s[read_c] = '\0';
		buf = ft_strjoin(buf, s);
		free (s);
		loc = ft_strchr(buf);
		if (loc != -1)
			break ;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*result;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	result = create_result(buf);
	buf = fill_buf(buf);
	return (result);
}

//printf("\n\nbreakpoint 1\n\n");
/*int main ()
{
    	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);

	printf("\noutput1\n");
	s = get_next_line(fd);
	printf("%s_________________________\n", s);

	printf("\noutput2\n");
	s = get_next_line(fd);
	printf("%s_________________________\n", s);

	printf("\noutput3\n");
	s = get_next_line(fd);
	printf("%s__________________________\n", s);
	return 0;
}*/


//read_c = read(fd, s, BUFFER_SIZE);
//s = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
//result = ft_strjoin(result, s);
	//return (result);