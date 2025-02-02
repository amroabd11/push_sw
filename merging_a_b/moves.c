/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:18:45 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/24 15:14:27 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_forward_moves(t_node *stack, int position)
{
	int	i;

	i = 0;
	while (stack->index != position)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_backward_moves(t_node *stack, int position)
{
	int	i;

	i = 0;
	while (stack->index != position)
		stack = stack->next;
	stack = stack->next;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i + 1);
}
