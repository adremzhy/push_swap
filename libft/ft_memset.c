/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:17:32 by adremzhy          #+#    #+#             */
/*   Updated: 2026/08/29 19:17:34 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*head;

	head = (unsigned char *)s;
	while (n > 0)
	{
		*head = (unsigned char)c;
		head++;
		n--;
	}
	return (s);
}
