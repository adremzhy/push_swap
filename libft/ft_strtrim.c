/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 05:29:01 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/06 05:29:02 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beggin;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	beggin = 0;
	while (s1[beggin] && ft_is_in_set(s1[beggin], set) == 1)
		beggin++;
	while (end > beggin && ft_is_in_set(s1[end - 1], set) == 1)
	{
		end--;
	}
	trimmed_str = ft_substr(s1, beggin, end - beggin);
	return (trimmed_str);
}
