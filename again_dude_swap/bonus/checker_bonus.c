/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:08:34 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/12 09:11:46 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

void	perform_operation(char *operator, t_node **stack_b, t_node **stack_a)
{
	// printf("oper : %s\n", operator);
	if (ft_strncmp(operator, "pb\n", 3) == 0)
	{
		printf("ddd\n");
		push(stack_a, stack_b, 'b');
	}
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
	else if (ft_strncmp(operator, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(operator, "sb\n", 3) == 0)
		sa_or_sb(stack_b," ");
	else
		error_exit();
}

int	gnl(t_oper **operations)
{
	char	*oper;
	t_oper	*temp;
	t_oper	*new;
	int		value;

	while ((oper = get_next_line(0)) != NULL)
	{
		value = check_oper(oper);
		if (!value)
		{
			free(oper);
			return (0);
		}
		new = ft_lstnew_two(oper);
		if (!new)
			return (0);
		if (*operations == NULL)
			*operations = new;
		else
			temp->next = new;
		temp = new;
		free(oper);
	}
	return (1);
}
void	sort_using_operations(t_node **stack_a)
{
	t_oper	*operations;
	t_node	*stack_b;
	int		check_oper;
	char 	*oper;

	stack_b = NULL;
	operations = NULL;
	check_oper = gnl(&operations);
	if (!check_oper)
	{
		free_s_operations(&operations);
		free_stack(stack_a);
		error_exit();
	}
	while (operations)
	{
		oper = operations->content;
		perform_operation(oper, &stack_b, stack_a);//TODO fix the problem within the operations
		free(oper);
		operations = operations->next;
	}
	free_s_operations(&operations);
	free_stack(&stack_b);
}

void	checker(t_node *stack_a, int i)
{
	if (sorted(stack_a) && (ft_lstsize(stack_a) == i))
		write(1, "OK\n", 3);
	else if (!sorted(stack_a) || !(ft_lstsize(stack_a) == i))
		write(1, "KO\n", 3);
}
// void f(){ system("leaks checker");}

int	main(int argc, char **argv)
{
	// atexit(f);
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
