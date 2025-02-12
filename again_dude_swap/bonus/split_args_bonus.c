/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:26:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:37:30 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
