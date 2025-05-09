/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:28:33 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 22:05:08 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_node	*ft_lstnew(long content)
{
	t_node	*aloc;

	aloc = (t_node *)malloc(sizeof(t_node));
	if (!aloc)
		return (NULL);
	aloc->content = content;
	aloc->next = NULL;
	aloc->index = 0;
	return (aloc);
}
