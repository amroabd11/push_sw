/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rot_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:35:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/11 13:47:24 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_node **stack_a, t_node **stack_b, char oper)
{
	t_node	*temp;
	t_node	*node_to_push;

	if (oper == 'a')
	{
		if (!stack_a || !*stack_b)
			return ;
		temp = *stack_b;
		(*stack_b) = (*stack_b)->next;
		temp->next = (*stack_a);
		*stack_a = temp;
	}
	else if (oper == 'b')
	{
		if (!stack_b || !*stack_a)
			return ;
		node_to_push = *stack_a;
		*stack_a = (*stack_a)->next;
		node_to_push->next = *stack_b;
		*stack_b = node_to_push;
	}
}

void	rr2(t_node **stack_a, t_node **stack_b, int ind)
{
	if (ind == 0)
	{
		reverse_rot(stack_a, NULL, -1);
		reverse_rot(stack_b, NULL, -1);
	}
	else
	{
		rotate(stack_a, NULL, 1);
		rotate(stack_b, NULL, 1);
	}
}
