/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_duplication.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:57:21 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/29 14:39:44 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_syntax_duplication(char *buffer, size_t length)
{
	char		**string;
	int			i;
	int			j;

	i = 0;
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
