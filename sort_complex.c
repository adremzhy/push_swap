/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:26:25 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:26:28 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while (max_rank > 0)
	{
		bits++;
		max_rank >>= 1;
	}
	return (bits);
}

void	radix_pass(t_stack *a, t_stack *b, int bit)
{
	int	count;

	count = a->size;
	while (count > 0)
	{
		if (((a->values[0] >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		count--;
	}
	while (b->size > 0)
		pa(a, b);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	bits;
	int	bit;

	if (is_sorted(a))
		return ;
	bits = get_bits(a->size - 1);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}
