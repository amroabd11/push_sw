/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:52 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:06 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	min(t_node *stack_a)
{
	int		min;

	min = stack_a->index;
	while (stack_a->next)
	{
		if (min > stack_a->next->index)
			min = stack_a->next->index;
		stack_a = stack_a->next;
	}
	return (min);
}

int	find_target(t_node *stack_b, t_node *stack_a)
{
	int		min_positive_diff;
	int		difference;
	int		target_index_node;
	int		first_dif;

	min_positive_diff = 2147483647;
	target_index_node = 0;
	first_dif = stack_a->index - stack_b->index;
	if ((stack_a->index - stack_b->index) > 0)
		min_positive_diff = stack_a->index - stack_b->index;
	while (stack_a->next)
	{
		difference = stack_a->next->index - stack_b->index;
		if (first_dif < difference)
			first_dif = difference;
		if (difference > 0 && difference < min_positive_diff)
			min_positive_diff = difference;
		stack_a = stack_a->next;
	}
	if (first_dif > 0)
		target_index_node = min_positive_diff + stack_b->index;
	else if (first_dif < 0)
		target_index_node = min(stack_a);
	return (target_index_node);
}
