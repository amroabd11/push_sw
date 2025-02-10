/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:33:52 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:28 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# define TRUE 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>
# define FALSE 0
# define MAX 2147483647

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				index;
	int				cost_a;
	int				cost_b;
	int				position;
}	t_node;

t_node	*ft_lstnew(long content);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
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
int		check_syntax_duplication(char *buffer, size_t length, int i);
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
