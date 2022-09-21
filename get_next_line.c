/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:57 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/21 20:39:36 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>

struct	s_tructVar
{
	int		bt_read;
	char	buf[BUFF_SIZE + 1];
} var;

char	*wh_remain(char *remain, char **line)
{
	char	*ptr_n;

	ptr_n = NULL;
	if (remain)
	{
		ptr_n = gnl_strchr(remain, '\n');
		if (ptr_n)
		{
			*ptr_n = '\0';
			*line = gnl_strdup(remain);
			++ptr_n;
			gnl_strlcpy(remain, ptr_n, gnl_strlen(ptr_n) + 1);
		}
		else
		{
			*line = gnl_strdup(remain);
			remain[0] = '\0';
		}
	}
	else
		*line = malloc(((int) sizeof(char)) * sizeof(char));
	return (ptr_n);
}

char	*x_cases(char **line, char **keep, char *remain)
{
	if (var.bt_read <= BUFF_SIZE && **line)
	{
		var.buf[0] = '\0';
		return (*line);
	}
	else if (var.bt_read <= 0)
	{
		if (remain)
			free(remain);
		free (*line);
		*line = NULL;
		return (NULL);
	}
	else
	{
		*keep = gnl_strjoin(*line, "\n");
		free(*line);
		return (*keep);
	}
}

char	*joining(char **ptr_n, char **remain, char **line, char **keep)
{
	**ptr_n = '\0';
	(*ptr_n)++;
	if (*remain)
		free(*remain);
	*remain = gnl_strdup(*ptr_n);
	*keep = *line;
	*line = gnl_strjoin(*line, var.buf);
	free(*keep);
	*keep = gnl_strjoin(*line, "\n");
	free(*line);
	return (*keep);
}

bool	func1(int fd)
{
	var.bt_read = read(fd, var.buf, BUFF_SIZE);
	if (var.bt_read)
		return (true);
	else
		return (false);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	char		*ptr_n;
	char		*keep;

	if (fd < 0)
		return ((char *)0);
	ptr_n = wh_remain(remain, &line);
	while ((!ptr_n) && func1(fd))
	{
		if (var.bt_read < 0)
		{
			free(line);
			return (NULL);
		}
		var.buf[var.bt_read] = '\0';
		ptr_n = gnl_strchr(var.buf, '\n');
		if (ptr_n)
			return (joining(&ptr_n, &remain, &line, &keep));
		keep = line;
		line = gnl_strjoin(line, var.buf);
		free(keep);
	}
	return (x_cases(&line, &keep, remain));
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	line = NULL;
// 	fd = open("myfile.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("-----------------------------------------------\n");
// 	printf("line:%s", line);
// 	while (line)
// 	{
// 		printf("line:%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	printf("-----------------------------------------------\n");

// 	return 0;
// }