/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:35:57 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/26 19:54:34 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(const char *s, size_t len)
{
	size_t	i;
	ssize_t	written;

	i = 0;
	written = 0;
	while (i < len)
	{
		written = write(1, s + i, len - i);
		if (written <= 0)
			return (-1);
		i = i + (size_t)written;
	}
	return ((int)len);
}

int	ft_print_char(char c)
{
	return (ft_write(&c, 1));
}

size_t	ft_str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_puts_string(const char *s)
{
	if (!s)
		return (ft_write("(null)", 6));
	return (ft_write(s, ft_str_len(s)));
}

int	ft_print_ptr(const void *p)
{
	int	n_lenght;

	if (!p)
		return (ft_write("(nil)", 5));
	if (ft_write("0x", 2) < 0)
		return (-1);
	n_lenght = ft_print_unsigned_num((unsigned long)p, FT_HEX_LOW);
	if (n_lenght < 0)
		return (-1);
	return (2 + n_lenght);
}
