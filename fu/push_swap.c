/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:32:54 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:44:17 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_from_b(t_node **stack_a, t_node **stack_b)
{
	int	position;

	while (*stack_b)
	{
		positions_init(stack_b, stack_a);
		costs(stack_b, stack_a);
		position = operations_num(stack_b);
		reorder_stacks(stack_b, stack_a, position);
		push_a(stack_b, stack_a);
	}
}

void	sort_stack(t_node **stack_a)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	if (sorted(*stack_a))
	{
		free_stack(stack_a);
		exit(0);
	}
	if (size == 2)
		sa_or_sb(stack_a, "sa");
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		bubble_sort_five(stack_a, &stack_b);
	else if (size > 5)
	{
		sort_forbig(stack_a, &stack_b, size - 3);
		sort_three(stack_a);
	}
	pushing_from_b(stack_a, &stack_b);
	complete_sorting_a(stack_a, 0);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	char	*buffer;
	t_node	*stack_a;
	size_t	length;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	buffer = NULL;
	buffer = put_or_split(argv, &buffer, 0);
	length = 0;
	if (!(check_syntax_duplication(buffer, length, 0) && valid(buffer)))
		error_exit();
	create_stack_a(&stack_a, &buffer);
	free(buffer);
	retreive_indexes(&stack_a);
	sort_stack(&stack_a);
	free_stack(&stack_a);
}
