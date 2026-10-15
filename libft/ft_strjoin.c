/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 05:00:15 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/06 05:00:16 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	lenth_s1;
	size_t	lenth_s2;
	size_t	i;
	size_t	j;

	lenth_s1 = ft_strlen(s1);
	lenth_s2 = ft_strlen(s2);
	new_string = malloc(sizeof(char) * (lenth_s1 + lenth_s2 + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < lenth_s1)
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < lenth_s2)
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}
