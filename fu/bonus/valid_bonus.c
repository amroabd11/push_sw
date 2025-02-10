/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:30:16 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:37:47 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_isdigit(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	valid(char *arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (ft_isdigit(arguments[i]) || arguments[i] == ' ')
			i++;
		else if (arguments[i] == '-' || arguments[i] == '+')
			i++;
		else if ((arguments[i] >= 9 && arguments[i] <= 13))
			i++;
		else
		{
			free(arguments);
			return (0);
		}
	}
	return (1);
}
