/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:00:24 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 22:05:49 by aamraouy         ###   ########.fr       */
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
	if (ft_strncmp(oper, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(oper, "sb", 2) == 0)
		write(1, "sb\n", 3);
}
