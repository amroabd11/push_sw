/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:23:42 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/29 15:20:45 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*put_or_split(char **argv, char **container, int j)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				break ;
			else if (argv[i][j + 1] == '\0')
			{
				free(*container);
				error_exit();
			}
			j++;
		}
		if (!argv[i][0])
		{
			free(*container);
			error_exit();
		}
		*container = ft_strjoin(*container, argv[i++]);
		*container = ft_strjoin(*container, " ");
	}
	return (*container);
}
