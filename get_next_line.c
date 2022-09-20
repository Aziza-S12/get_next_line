/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:57 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/20 17:08:45 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*wh_remain(char *remain, char **line)
{
	char *ptr_n;
	
	ptr_n = NULL;
	if(remain)
	{
		if((ptr_n = gnl_strchr(remain, '\n')))
		{
			*ptr_n = '\0';
			*line = gnl_strdup(remain);
			gnl_strcpy(remain, ++ptr_n);
		}
		else
		{
			*line = gnl_strdup(remain);
			remain[0] = '\0';
		}
	}
	else
		*line = gnl_calloc(sizeof(char));
	return(ptr_n);
}

char	*gnl_calloc(int count)
{
	char *str;
	int it;
	
	it = 0;
	str = malloc (count * sizeof(char));
	if (!str)
		return (NULL);
	while (it < count)
		str[it++] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char 		*line;
	char		buf[BUFF_SIZE + 1];
	int			bt_read;
	char		*ptr_n;
	char		*keep;

	if (fd < 0)
		return ((char *)0);
	ptr_n = wh_remain(remain, &line);
	while (!ptr_n && (bt_read = read(fd, buf, BUFF_SIZE)))
	{
		if (bt_read < 0)
		{
			free(line);
			return (NULL);
		}
		buf[bt_read] = '\0';
		if((ptr_n = gnl_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			if (remain) free(remain);
			remain = gnl_strdup(ptr_n);
			keep = line;
			line = gnl_strjoin(line, buf);
			free(keep);
			keep = gnl_strjoin(line, "\n");
			free(line);
			return (keep);
		}
		keep = line;
		line = gnl_strjoin(line, buf);
		free(keep);
	}
	if (bt_read <= BUFF_SIZE && *line)
	{
		buf[0] = '\0';
		return (line);
	}
	else if (bt_read <= 0)
	{
		if (remain) free(remain);
	 	free(line);
		line = NULL;
		return (NULL);
	}
	else // bt_read <= BUFF_SIZE && !(*line)
	{
		keep = gnl_strjoin(line, "\n");
		free(line);
		return (keep);
	}
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

// 	//while(1);

// 	return 0;
// }
