/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:59 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/20 15:23:05 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //open
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 42

char	*get_next_line(int fd);
char	*wh_remain(char *remain, char **line);
char	*gnl_strdup(const char *str1);
int		gnl_strlen(const char *str);
char	*gnl_calloc(int count);
char	*gnl_strchr(const char *str, int f);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strcpy(char *dest, const char *src);
size_t	gnl_strlcpy(char *dest, const char *src, size_t dsize);

#endif