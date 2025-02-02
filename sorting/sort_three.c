/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:12:35 by aamraouy          #+#    #+#             */
/*   Updated: 2025/01/25 18:43:02 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = ft_lstlast(*stack)->content;
	if (sorted(*stack))
		return ;
	if (first > second && first < third)
		sa_or_sb(stack, "sa");
	else if (first < third && first < second)
	{
		sa_or_sb(stack, "sa");
		rotate(stack, "ra\n", 1);
	}
	else if (first > second && second < third)
		rotate(stack, "ra\n", 1);
	else if (first > second && second > third)
	{
		rotate(stack, "ra\n", 1);
		sa_or_sb(stack, "sa");
	}
	else if (first < second && first > third)
		reverse_rot(stack, "rra\n", -1);
}
