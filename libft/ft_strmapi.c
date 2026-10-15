/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:06:36 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/11 10:06:38 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*modified;
	size_t	i;

	if (!s)
		return (NULL);
	modified = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!modified)
		return (NULL);
	i = 0;
	while (s[i])
	{
		modified[i] = f(i, s[i]);
		i++;
	}
	modified[i] = '\0';
	return (modified);
}
