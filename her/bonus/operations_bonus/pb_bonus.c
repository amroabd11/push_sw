/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:37:10 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 22:05:35 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;

	if (!stack_b || !*stack_a || !(*stack_a)->next)
		return ;
	node_to_push = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_push->next = *stack_b;
	*stack_b = node_to_push;
	write(1, "pb\n", 3);
}
