/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:16:52 by asadritd          #+#    #+#             */
/*   Updated: 2022/09/15 20:13:32 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*gnl_strchr()

char	*gnl_strjoin()

char	*gnl_strcpy()

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

strclr 

