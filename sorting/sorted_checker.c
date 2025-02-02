/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:33:45 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:43:18 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
