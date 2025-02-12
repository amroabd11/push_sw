/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:45:28 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/11 12:00:20 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	check_oper(char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(operation, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(operation, "rrr\n", 4) == 0)
		return (1);
	if (ft_strncmp(operation, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(operation, "pb\n", 3) == 0)
		return (1);
	else
		return (0);
}
