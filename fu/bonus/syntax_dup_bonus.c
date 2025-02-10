/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_dup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:28:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:37:40 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_syntax_duplication(char *buffer, size_t length, int i)
{
	char		**string;
	int			j;

	string = ft_split(buffer, ' ');
	while (string[i])
	{
		j = i + 1;
		while (string[j])
		{
			length = ft_strlen(string[i]);
			if (length < ft_strlen(string[j]))
				length = ft_strlen(string[j]);
			if (ft_strncmp(string[i], string[j], length) == 0)
			{
				free(buffer);
				free_split(string);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_split(string);
	return (1);
}
