/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:03 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/02 09:03:34 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
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
#endif