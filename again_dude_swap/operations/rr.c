/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:47:27 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 17:51:09 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rotate(stack_a, NULL, 1);
		rotate(stack_b, NULL, 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(stack_a, "ra\n", cost_a);
	rotate(stack_b, "rb\n", cost_b);
}
