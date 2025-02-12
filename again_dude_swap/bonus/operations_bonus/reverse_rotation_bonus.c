/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:51:11 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 22:05:38 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	reverse_rot(t_node **stack, char *operator, int cost)
{
	t_node	*temp;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (cost < 0)
	{
		temp = ft_lstlast(*stack);
		second_last = *stack;
		while (second_last->next != NULL
			&&second_last->next->content != temp->content)
			second_last = second_last->next;
		second_last->next = NULL;
		temp->next = (*stack);
		*stack = temp;
		if (operator)
			write(1, operator, 4);
		cost++;
	}
}
