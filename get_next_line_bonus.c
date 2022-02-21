/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:23 by mraspors          #+#    #+#             */
/*   Updated: 2022/02/19 03:40:30 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buf(char *buf, int loc)
{
	char	*result;

	result = NULL;
	if (loc == -1)
		result = NULL;
	else
		result = ft_strjoin(NULL, &buf[loc + 1]);
	free(buf);
	buf = NULL;
	return (result);
}

char	*create_result(char *buf, int loc)
{
	char	c;
	char	*result;

	if (!buf)
		return (NULL);
	if (loc == -1)
	{
		result = ft_strjoin(NULL, buf);
		return (result);
	}
	c = buf[loc + 1];
	buf[loc + 1] = '\0';
	result = ft_strjoin(NULL, buf);
	buf[loc + 1] = c;
	return (result);	
}
char	*ft_read(int fd, char *buf)
{
	char	s[BUFFER_SIZE + 1];
	int	read_c;

	read_c = 1;
	while(ft_strchr(buf) == -1)
	{
		read_c = read(fd, s, BUFFER_SIZE);
		if (read_c <= 0)
			break ;
		s[read_c] = '\0';
		buf = ft_strjoin(buf, s);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[256];
	char		*result;
	int		loc;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 255)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd]);
	if(buf[fd] == NULL)
		return (NULL);
	loc = ft_strchr(buf[fd]); 
	result = create_result(buf[fd], loc);
	buf[fd] = fill_buf(buf[fd], loc);
	if(result[0] == '\0')
		result = NULL;
	return (result);
}

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
	printf("%s__________________________\n\n", s);

	printf("\noutput4\n");
	s = get_next_line(fd);
	printf("%s__________________________\n\n", s);

	printf("\noutput5\n");
	s = get_next_line(fd);
	printf("%s__________________________\n\n", s);

	printf("\noutput6\n");
	s = get_next_line(fd);
	printf("%s__________________________\n\n", s);

	printf("\noutput7\n");
	s = get_next_line(fd);
	printf("%s__________________________\n\n", s);

	return 0;
}*/