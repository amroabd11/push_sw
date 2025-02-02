/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:33:52 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/02 09:57:57 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# define TRUE 1

void	retreive_indexes(t_node **stack_a);
void	positions_init(t_node **stack_b, t_node **stack_a);
void	bubble_sort_five(t_node **stack_a, t_node **stack_b);
char	*put_or_split(char **argv, char **container, int j);
int		operations_num(t_node **stack_b);
int		count_backward_moves(t_node *stack, int position);
int		count_forward_moves(t_node *stack, int position);
int		valid(char *arguments);
void	rotate(t_node **stack, char *operator, int cost);
void	error_exit(void);
void	reverse_rot(t_node **stack, char *operator, int cost);
void	complete_sorting_a(t_node **stack_a, int index);
void	rrr(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);
void	rr(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);
void	create_stack_a(t_node **stack_a, char **arg);
int		find_target(t_node *stack_b, t_node *stack_a);
int		check_syntax_duplication(char *buffer, size_t length);
void	sort_number_inarray(int **ar, int len);
void	pb(t_node **stack_a, t_node **stack_b);
void	sort_forbig(t_node **stack_a, t_node **stack_b, int size);
void	sort_three(t_node **stack);
void	costs(t_node **stack_b, t_node **stack_a);
void	sa_or_sb(t_node **stack, char *oper);
void	retreive_node_index(t_node **stack_a, int *array, int len);
int		sorted(t_node *stack_a);
void	free_split(char **to_free);
void	reorder_stacks(t_node **stack_b, t_node **stack_a, int best_pos);
void	push_a(t_node **stack_b, t_node **stack_a);
void	free_stack(t_node **stack);

#endif