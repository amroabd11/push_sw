/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:39:56 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/09 09:39:42 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	*fill_s(char const *s, char c)
{
	char	*mem_fill;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	mem_fill = (char *)malloc(i + 1);
	if (!mem_fill)
		return (NULL);
	ft_strlcpy(mem_fill, s, i + 1);
	return (mem_fill);
}

static int	free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != NULL)
			free(s[i]);
		i++;
	}
	free(s);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**lst;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_countword(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		lst[j] = fill_s(s + i, c);
		if (!lst[j] && free_s(lst))
			return (NULL);
		i += ft_strlen(lst[j]);
		j++;
	}
	lst[j] = NULL;
	return (lst);
}
