/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:33:58 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/12 18:34:01 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_word_count(const char *s, char c)
{
	int		i;
	int		inword;
	size_t	total;

	inword = 0;
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			total++;
			inword = 1;
		}
		else if (s[i] == c)
		{
			inword = 0;
		}
		i++;
	}
	return (total);
}

static void	*ft_free_all(char **set, int i)
{
	while (i > 0)
	{
		i--;
		free(set[i]);
	}
	free(set);
	return (NULL);
}

static char	*word_in_line(char const *s, char c, int *j)
{
	int	start;

	while (s[*j] && s[*j] == c)
		(*j)++;
	start = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
	return (ft_substr(s, start, *j - start));
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = ft_word_count(s, c);
	tab = malloc(sizeof(char *) * (words_count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words_count)
	{
		tab[i] = word_in_line(s, c, &j);
		if (!tab[i])
			return (ft_free_all(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
