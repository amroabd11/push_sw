/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:30:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:26 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **stack, char *operator, int cost)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (cost > 0)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		last = ft_lstlast(*stack);
		last->next = temp;
		if (operator)
			write(1, operator, 3);
		cost--;
	}
}
