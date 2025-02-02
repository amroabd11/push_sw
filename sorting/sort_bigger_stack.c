/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:18:17 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/29 08:30:31 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_average(t_node **stack)
{
	int		i;
	int		sum;
	int		average;
	t_node	*temp;

	i = 0;
	sum = 0;
	average = 0;
	temp = *stack;
	while (temp)
	{
		sum += temp->index;
		i++;
		temp = temp->next;
	}
	if (sum % i == 0)
		average = sum / i;
	else if ((sum % i) != 0)
		average = (sum / i) + 1;
	return (average);
}

static void	pushb(int *i, int *num_of_pushes, t_node **st_a, t_node **st_b)
{
	pb(st_a, st_b);
	(*i)--;
	(*num_of_pushes)--;
}

void	push_in_b(t_node **stack_a, t_node **stack_b, int *nodes_to_push)
{
	int	average;
	int	i;

	average = find_average(stack_a);
	i = ((*nodes_to_push) / 2 + 1);
	while (i > 0)
	{
		if ((*stack_a)->index < average)
			pushb(&i, nodes_to_push, stack_a, stack_b);
		else if ((*stack_a)->next->index < average)
		{
			rotate(stack_a, "ra\n", 1);
			pushb(&i, nodes_to_push, stack_a, stack_b);
		}
		else if (ft_lstlast(*stack_a)->index < average)
		{
			reverse_rot(stack_a, "rra\n", -1);
			pushb(&i, nodes_to_push, stack_a, stack_b);
		}
		else
			rotate(stack_a, "ra\n", 1);
	}
}

void	sort_forbig(t_node **stack_a, t_node **stack_b, int size_rest)
{
	while (size_rest > 0)
	{
		push_in_b(stack_a, stack_b, &size_rest);
	}
}
