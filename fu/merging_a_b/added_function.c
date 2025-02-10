/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:09:10 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/03 08:44:00 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	retreive_indexes(t_node **stack_a)
{
	int		*sort_array;
	int		len;
	int		ind;
	t_node	*temp;

	ind = 0;
	temp = *stack_a;
	len = ft_lstsize(*stack_a);
	sort_array = malloc(sizeof(int) * len);
	if (!sort_array)
		return ;
	while (temp)
	{
		sort_array[ind++] = (temp)->content;
		temp = temp->next;
	}
	ind = 0;
	sort_number_inarray(&sort_array, len);
	temp = *stack_a;
	retreive_node_index(&temp, sort_array, len);
	*stack_a = temp;
	free(sort_array);
}

void	create_stack_a(t_node **stack_a, char **arg)
{
	char	**splt;
	int		i;
	long	number;
	t_node	*node;

	i = 0;
	splt = ft_split(*arg, ' ');
	if (!splt[i])
		error_exit();
	while (splt[i])
	{
		number = ft_atoi(splt[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			free_split(splt);
			free_stack(stack_a);
			error_exit();
		}
		node = ft_lstnew(number);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	free_split(splt);
}
