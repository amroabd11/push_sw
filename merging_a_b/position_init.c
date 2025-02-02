/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:47:57 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:20:32 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	positions_init(t_node **stack_b, t_node **stack_a)
{
	int		i;
	t_node	*temp1;
	t_node	*temp2;

	i = 0;
	temp1 = *stack_a;
	temp2 = *stack_b;
	while (temp1)
	{
		temp1->position = i++;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp2)
	{
		temp2->position = i++;
		temp2 = temp2->next;
	}
}
