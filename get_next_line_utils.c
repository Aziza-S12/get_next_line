/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:52 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/17 18:51:08 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef GET_NEXT_LINE_UTILS
# define GET_NEXT_LINE_UTILS

char	*gnl_strdup(const char *str1)
{
	int i;
	int len; 
	char *str2;

	len = 0;
	while (str1[len])
		len++;
	str2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str2))
	{
		return(NULL);
	}
	i = 0;
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;		
	}
	str2[i] = '\0';
	return (str2);
}

int	gnl_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return(i);	
}

char	*gnl_strchr(const char *s, int f)
{
	char	find;
	int		i;

	find = (unsigned char)f;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	j;
	size_t	n;
	char	*s;

	j = 0;
	n = 0;
	s = (char *)src;
	if (!dest)
	{
		return (0);
	}
	n = gnl_strlen(s);
	if (!dsize)
	{
		return (n);
	}
	while (s[j] && j < dsize - 1)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (n);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_l;
	int		s2_l;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (gnl_strdup(s1));
	s1_l = gnl_strlen(s1);
	s2_l = gnl_strlen(s2);
	newstr = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!newstr)
		return (NULL);
	gnl_strlcpy(newstr, s1, s1_l + 1);
	gnl_strlcpy(newstr + s1_l, s2, s2_l + 1);
	return (newstr);
}

#endif