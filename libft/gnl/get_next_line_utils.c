/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:00:24 by adremzhy          #+#    #+#             */
/*   Updated: 2026/10/07 21:06:02 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_free_str(char *str)
{
	free(str);
	return (NULL);
}

char	*gnl_strchr(const char *s, int c)
{
	int		i;
	char	conv;

	conv = (char)c;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == conv)
			return ((char *)&s[i]);
		i++;
	}
	if (conv == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_strjoin_free(char *s1, const char *s2)
{
	size_t		i;
	size_t		len_s1;
	size_t		len_s2;
	char		*united_str;

	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	united_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!united_str)
	{
		gnl_free_str(s1);
		return (NULL);
	}
	i = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			united_str[i] = s1[i];
		else
			united_str[i] = s2[i - len_s1];
		i++;
	}
	united_str[i] = '\0';
	free(s1);
	return (united_str);
}
