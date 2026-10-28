/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:25:14 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/28 15:23:49 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_below(t_stack *a, int limit)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->values[i] < limit)
			return (i);
		i++;
	}
	return (-1);
}

void	push_chunk(t_stack *a, t_stack *b, int limit)
{
	int	pos;

	pos = find_below(a, limit);
	while (pos != -1)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
		pb(a, b);
		pos = find_below(a, limit);
	}
}

void	sort_medium(t_stack *a, t_stack *b, int chunk_size)
{
	int	limit;

	if (is_sorted(a))
		return ;
	limit = chunk_size;
	while (a->size > 0)
	{
		push_chunk(a, b, limit);
		limit += chunk_size;
	}
	while (b->size > 0)
	{
		max_to_top(b);
		pa(a, b);
	}
}

int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (((long)((size + 1) * (size + 1))) <= n)
		size++;
	return (size);
}
