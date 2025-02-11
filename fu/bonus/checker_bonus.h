/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:56:30 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/11 12:12:20 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
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

typedef	struct s_operations
{
	char				*content;
	struct s_operations	*next;
} t_oper;

void	ss(t_node **stack_a, t_node **stack_b);
void	free_s_operations(t_oper **operations);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		check_oper(char *operation);
t_oper	*ft_lstnew_two(char *content);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(long content);
int		ft_lstsize(t_node *lst);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_exit(void);
int		valid(char *arguments);
int		sorted(t_node *stack_a);
void	rotate(t_node **stack, char *operator, int cost);
void	reverse_rot(t_node **stack, char *operator, int cost);
void	sa_or_sb(t_node **stack, char *oper);
void	pb(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node **stack);
void	free_split(char **to_free);
int		check_syntax_duplication(t_node *stack_a);
void	create_stack_a(t_node **stack_a, char **arg);
void	retreive_node_index(t_node **stack_a, int *array, int len);
void	sort_number_inarray(int **ar, int len);
void	retreive_indexes(t_node **stack_a);
void	rr2(t_node **stack_a, t_node **stack_b, int ind);
void	push(t_node **stack_a, t_node **stack_b, char oper);
char	*put_or_split(char **argv, char **container, int j);
char	*get_next_line(int fd);
size_t	f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(char *s, int c);

#endif
