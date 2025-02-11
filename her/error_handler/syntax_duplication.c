/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_duplication.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:57:21 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 12:08:31 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_syntax_duplication(t_node *stack_a)
{
	t_node *temp;

	t_node *current = stack_a;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->content == temp->content)
				return (0);
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}
