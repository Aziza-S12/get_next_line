/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:57 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/13 20:01:50 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char 		*line;
	
	read(fd, str, 10);
	buff[10] = '\0'
	*line = ft_strdup(buff);
	
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;
	
	fd = open("myfile.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("line:%s\xA", line);

	return 0;
}
