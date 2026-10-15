/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:32:20 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/11 11:32:22 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		lenght;
	long	num;
	char	*con_str;

	lenght = ft_intlen(n);
	con_str = malloc(sizeof(char) * (lenght + 1));
	if (!con_str)
		return (NULL);
	con_str[lenght] = '\0';
	num = n;
	if (num < 0)
	{
		con_str[0] = '-';
		num = -num;
	}
	if (num == 0)
		con_str[0] = '0';
	while (num != 0)
	{
		con_str[--lenght] = (num % 10) + '0';
		num = num / 10;
	}
	return (con_str);
}
