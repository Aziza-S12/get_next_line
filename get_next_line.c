/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:57 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/15 19:21:22 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	wh_remain(char *remain, char **line)
{
	char *ptr_n;
	
	ptr_n = NULL;
	if(remain)	
		if((ptr_n = ft_strchr(remain, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(remain);
			ft_strcpy(remain, ++ptr_n);
		}
		else
		{
			*line = ft_strdup(remain);
			strclr(remain);
		}
	else
		*line = strnew(1);
	return(ptr_n);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char 		**line;
	char		buf[BUFF_SIZE + 1];
	int			bt_read;
	char		*ptr_n;
	char		*keep;

	ptr_n = wh_remained(remain, line);
	while (!ptr_n && (bt_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[bt_read] = '\0';
		if((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			remain = ft_strdup(ptr_n);
		}
		keep = *line;
		*line = ft_strjoin(*line, buf);
		free(keep);
	}
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;
	
	fd = open("myfile.txt", O_RDONLY);
	get_next_line(fd);
	printf("line:%s\xA", line);

	get_next_line(fd);
	printf("line:%s\xA\xA", line);
	
	return 0;
}
