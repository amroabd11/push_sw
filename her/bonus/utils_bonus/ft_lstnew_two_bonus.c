/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:22:53 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/11 11:24:15 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_oper	*ft_lstnew_two(char *content)
{
	t_oper	*aloc;

	aloc = (t_oper *)malloc(sizeof(t_oper));
	if (!aloc)
		return (NULL);
	aloc->content = content;
	aloc->next = NULL;
	return (aloc);
}
