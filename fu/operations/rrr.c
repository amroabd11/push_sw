/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:35:28 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:01:09 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	while ((cost_a < 0) && (cost_b < 0))
	{
		reverse_rot(stack_a, NULL, -1);
		reverse_rot(stack_b, NULL, -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	reverse_rot(stack_a, "rra\n", cost_a);
	reverse_rot(stack_b, "rrb\n", cost_b);
}
