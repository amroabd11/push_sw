/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:00:23 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/29 15:21:16 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_min(t_node *stacka)
{
	t_node	*min;

	min = stacka;
	while (stacka)
	{
		if (min->content > stacka->content)
			min = stacka;
		stacka = stacka->next;
	}
	return (min);
}

void	move_to_top(t_node **stacka, t_node *min)
{
	t_node	*temp;
	int		ind;

	ind = 0;
	temp = *stacka;
	while (temp->index != min->index)
	{
		ind++;
		temp = temp->next;
	}
	if (ind <= 2)
	{
		while (ind--)
			rotate(stacka, "ra\n", 1);
	}
	else
	{
		ind = ft_lstsize(*stacka) - ind;
		while (ind--)
			reverse_rot(stacka, "rra\n", -1);
	}
}

void	sort_four(t_node **stacka, t_node **stackb)
{
	t_node	*min;

	min = find_min(*stacka);
	move_to_top(stacka, min);
	pb(stacka, stackb);
	sort_three(stacka);
	push_a(stackb, stacka);
}

void	bubble_sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	temp = find_min(*stack_a);
	move_to_top(stack_a, temp);
	pb(stack_a, stack_b);
	temp = find_min(*stack_a);
	move_to_top(stack_a, temp);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
