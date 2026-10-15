/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 03:51:14 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/06 03:51:15 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_str(void)
{
	char	*sub;

	sub = malloc(sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total_needed;
	char	*sub;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_empty_str());
	if (str_len - start < len)
		total_needed = str_len - start;
	else
		total_needed = len;
	sub = malloc(sizeof(char) * (total_needed + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < total_needed)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
