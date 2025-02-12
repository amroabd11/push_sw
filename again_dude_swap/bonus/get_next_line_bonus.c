/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:44:57 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/07 12:04:57 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*read_bytes_until_buffsize(int fd, char *static_str)
{
	char		*temp_buffer;
	ssize_t		read_byt;

	read_byt = 1;
	temp_buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	while (read_byt != 0 && !f_strchr(static_str, '\n'))
	{
		read_byt = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_byt < 0)
		{
			free(temp_buffer);
			free(static_str);
			return (NULL);
		}
		temp_buffer[read_byt] = '\0';
		static_str = f_strjoin(static_str, temp_buffer);
	}
	free(temp_buffer);
	return (static_str);
}

static char	*add_line(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (buffer[j] && i > j)
	{
		str[j] = buffer[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char	*retreive_rest(char *rest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free(rest), NULL);
	if (rest[i] == '\n')
		i++;
	str = malloc(f_strlen(rest) - i + 1);
	if (!str)
		return (NULL);
	while (f_strlen(rest) - i)
		str[j++] = rest[i++];
	str[j] = '\0';
	free(rest);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stat_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_buffer = read_bytes_until_buffsize(fd, stat_buffer);
	if (!stat_buffer)
		return (NULL);
	line = add_line(stat_buffer);
	stat_buffer = retreive_rest(stat_buffer);
	return (line);
}
