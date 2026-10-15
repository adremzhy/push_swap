/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:20:08 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/26 19:47:31 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_num(unsigned long n, const char *to_type)
{
	char			local_b[32];
	unsigned long	retrieval;
	int				len;

	retrieval = ft_str_len(to_type);
	len = 0;
	if (n == 0)
	{
		local_b[31] = to_type[0];
		len = 1;
	}
	while (n > 0)
	{
		len++;
		local_b[32 - len] = to_type[n % retrieval];
		n = n / retrieval;
	}
	return (ft_write(local_b + ('a' - 'A') - len, len));
}

int	ft_print_signed(int n)
{
	unsigned int	trav;
	int				sign;
	int				n_len;

	sign = 0;
	trav = (unsigned int)n;
	if (n < 0)
	{
		if (ft_print_char('-') < 0)
			return (-1);
		sign = 1;
		if (n == INT_MIN)
			trav = (unsigned int)INT_MAX + 1u;
		else
			trav = (unsigned int)(-n);
	}
	n_len = ft_print_unsigned_num(trav, FT_DECIMAL);
	if (n_len < 0)
		return (-1);
	return (sign + n_len);
}
