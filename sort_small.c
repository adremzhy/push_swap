/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:25:52 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:25:58 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->values[0] > a->values[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->values[0] > a->values[1]
		&& a->values[0] > a->values[2])
	{
		ra(a);
	}
	else if (a->values[1] > a->values[0]
		&& a->values[1] > a->values[2])
	{
		rra(a);
	}
	if (a->values[0] > a->values[1])
		sa(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4 || a->size == 5)
		sort_four_five(a, b);
	else if (a->size > 5)
		sort_medium(a, b, get_chunk_size(a->size));
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
