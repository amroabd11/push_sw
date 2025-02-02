/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:38:55 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:42:37 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_number_inarray(int **ar, int len)
{
	int	i;
	int	*array;
	int	temp;

	i = 0;
	array = *ar;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	*ar = array;
}
