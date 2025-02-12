/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:00:24 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/11 12:14:28 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	sa_or_sb(t_node **stack, char *oper)
{
	int	temp;
	int	index;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	index = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = index;
	if (ft_strncmp(oper, " ", 1) == 0)
		return ;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa_or_sb(stack_a, " ");
	sa_or_sb(stack_b, " ");
}