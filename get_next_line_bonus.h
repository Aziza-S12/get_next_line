/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:40:12 by asadritd          #+#    #+#             */
/*   Updated: 2022/10/03 13:21:30 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> //open
# include <unistd.h>
# include <stdlib.h>
#include "get_next_line_bonus.h"
#include <stdbool.h>
# define BUFF_SIZE 42

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