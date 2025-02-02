/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushTo_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:47:05 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:25:12 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complete_sorting_a(t_node **stack_a, int index)
{
	t_node	*temp;
	int		back;
	int		forward;

	temp = *stack_a;
	if (temp->index == index)
		return ;
	back = count_backward_moves(*stack_a, index);
	forward = count_forward_moves(*stack_a, index);
	if (back > forward)
	{
		while (forward-- > 0)
			rotate(stack_a, "ra\n", 1);
	}
	else if (back < forward)
	{
		while (back-- > 0)
			reverse_rot(stack_a, "rra\n", -1);
	}
}

int	operations_num(t_node **stack_b)
{
	int		min_operation;
	int		cost_a;
	t_node	*temp;
	int		cost_b;
	int		position_nedded;

	min_operation = 2147483647;
	temp = *stack_b;
	while (temp)
	{
		cost_a = temp->cost_a;
		if (cost_a < 0)
			cost_a = (temp->cost_a * -1);
		cost_b = temp->cost_b;
		if (cost_b < 0)
			cost_b = (temp->cost_b * -1);
		if ((cost_a + cost_b) < min_operation)
		{
			min_operation = (cost_a + cost_b);
			position_nedded = temp->position;
		}
		temp = temp->next;
	}
	return (position_nedded);
}

void	reorder_stacks(t_node **stack_b, t_node **stack_a, int best_pos)
{
	t_node	*temp;

	temp = *stack_b;
	while (temp->position != best_pos)
		temp = temp->next;
	if ((temp->cost_a < 0) && (temp->cost_b < 0))
		rrr(stack_a, stack_b, temp->cost_a, temp->cost_b);
	else if ((temp->cost_a > 0) && (temp->cost_b > 0))
		rr(stack_a, stack_b, temp->cost_a, temp->cost_b);
	else if (temp->cost_a >= 0 && temp->cost_b <= 0)
	{
		reverse_rot(stack_b, "rrb\n", temp->cost_b);
		rotate(stack_a, "ra\n", temp->cost_a);
	}
	else if ((temp->cost_a <= 0) && (temp->cost_b >= 0))
	{
		rotate(stack_b, "rb\n", temp->cost_b);
		reverse_rot(stack_a, "rra\n", temp->cost_a);
	}
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*temp;

	if (!stack_a || !*stack_b)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	temp->next = (*stack_a);
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	costs(t_node **stack_b, t_node **stack_a)
{
	int		target;
	int		back_moves;
	int		size_b;
	t_node	*temp;

	size_b = ft_lstsize(*stack_b);
	temp = *stack_b;
	while (temp)
	{
		temp->cost_b = temp->position;
		if (temp->cost_b > size_b / 2)
			temp->cost_b = temp->position - size_b;
		target = find_target(temp, *stack_a);
		back_moves = count_backward_moves(*stack_a, target);
		temp->cost_a = count_forward_moves(*stack_a, target);
		if (back_moves < temp->cost_a)
			temp->cost_a = back_moves * -1;
		temp = temp->next;
	}
}
