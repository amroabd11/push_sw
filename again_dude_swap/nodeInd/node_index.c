/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:05:49 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:44:25 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	retreive_node_index(t_node **stack_a, int *array, int len)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->content == array[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}
