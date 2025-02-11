/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:20:00 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 22:04:46 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

long	ft_atoi(const char *str)
{
	int		sign;
	int		next_digit;
	long	result;

	sign = 1;
	result = 0;
	while ((*str == ' '))
		str++;
	if ((*str == '-' || *str == '+') && *(str + 1))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (2147483648);
		next_digit = *str - '0';
		result = result * 10 + next_digit;
		str++;
	}
	if (*str)
		return (2147483648);
	return (result * sign);
}
