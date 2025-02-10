/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:08:34 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 20:15:13 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	perform_operation(char *operator, t_node **stack_b, t_node **stack_a)
{
	if (ft_strncmp(operator, "pb\n", 3) == 0)
		push(stack_a, stack_b, 'b');
	else if (ft_strncmp(operator, "pa\n", 3) == 0)
		push(stack_a, stack_b, 'a');
	else if (ft_strncmp(operator, "ra\n", 3) == 0)
		rotate(stack_a, NULL, 1);
	else if (ft_strncmp(operator, "rb\n", 3) == 0)
		rotate(stack_b, NULL, 1);
	else if (ft_strncmp(operator, "rra\n", 4) == 0)
		reverse_rot(stack_a, NULL, -1);
	else if (ft_strncmp(operator, "rrb\n", 4) == 0)
		reverse_rot(stack_b, NULL, -1);
	else if (ft_strncmp(operator, "sa\n", 3) == 0)
		sa_or_sb(stack_a, " ");
	else if (ft_strncmp(operator, "rrr\n", 4) == 0)
		rr2(stack_a, stack_b, 0);
	else if (ft_strncmp(operator, "rr\n", 3) == 0)
		rr2(stack_a, stack_b, 1);
	else
		error_exit();
}

void	sort_using_operations(t_node **stack_a)
{
	char	*operations;
	t_node	*stack_b;

	stack_b = NULL;
	operations = get_next_line(0);
	while (operations)
	{
		perform_operation(operations, &stack_b, stack_a);
		free(operations);
		operations = get_next_line(0);
	}
	free_stack(&stack_b);
}

void	checker(t_node *stack_a, int i)
{
	if (sorted(stack_a) && (ft_lstsize(stack_a) == i))
		write(1, "OK\n", 3);
	else if (!sorted(stack_a) || !(ft_lstsize(stack_a) == i))
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char	*buffer;
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	buffer = NULL;
	buffer = put_or_split(argv, &buffer, 0);
	if (!valid(buffer))
		error_exit();
	create_stack_a(&stack_a, &buffer);
	if (!check_syntax_duplication(stack_a))
	{
		free_stack(&stack_a);
		free(buffer);
		error_exit();
	}
	free(buffer);
	retreive_indexes(&stack_a);
	i = ft_lstsize(stack_a);
	sort_using_operations(&stack_a);
	checker(stack_a, i);
	free_stack(&stack_a);
}
