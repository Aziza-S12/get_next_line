/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:52 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/16 20:36:47 by asadritd         ###   ########.fr       */
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

char	gnl_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return(i);	
}

char	gnl_strchr(const char *str, int f)
{
	char	*x;
	int		i;
	int		len;
	
	i = 0;
	x = (char *)str;
	len = gnl_strlen(x);
	while (i <= len)
	{
		if (x[i] == (char)f)
			return (&x[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char const *str1, char const *str2)
{
	char	*newstr;
	int		s1_l;
	int		s2_l;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (gnl_strdup(str2));
	if (!str2)
		return (gnl_strdup(str1));
	s1_l = gnl_strlen(str1);
	s2_l = gnl_strlen(str2);
	newstr = malloc(sizeof( char) * (s1_l + s2_l + 1));
	if (!newstr)
		return (NULL);
	gnl_strcpy(newstr, str1, s1_l + 1);
	gnl_strcpy(newstr + s1_l, str2, s2_l + 1);
	return (newstr);
}

size_t	gnl_strcpy(char *dest, const char *src)
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

#endif