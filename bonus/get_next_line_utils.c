/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:16:45 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/02 09:55:10 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (*s)
	{
		index++;
		s++;
	}
	return (index);
}

char	*f_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*alloc;
	size_t	space;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	space = f_strlen(s1) + f_strlen(s2);
	alloc = (char *)malloc(space + 1);
	if (!alloc)
		return (NULL);
	space = -1;
	j = 0;
	while (s1[++space])
		alloc[space] = s1[space];
	while (s2[j])
		alloc[space++] = s2[j++];
	alloc[f_strlen(s1) + f_strlen(s2)] = '\0';
	free(s1);
	return (alloc);
}
