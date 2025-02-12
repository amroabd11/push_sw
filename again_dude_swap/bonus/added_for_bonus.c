/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added_for_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:24:15 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:37:14 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort_number_inarray(int **ar, int len)
{
	int	i;
	int	*array;
	int	temp;

	i = 0;
	array = *ar;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	*ar = array;
}

void	retreive_node_index(t_node **stack_a, int *array, int len)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->content == array[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

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
