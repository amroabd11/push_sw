/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_dup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:28:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:37:40 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
