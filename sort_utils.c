/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:26:04 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:26:13 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	min_index(t_stack *a)
{
	int	i;
	int	min;

	min = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->values[i] < a->values[min])
			min = i;
		i++;
	}
	return (min);
}

void	min_to_top(t_stack *a)
{
	int	pos;

	pos = min_index(a);
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		pos = a->size - pos;
		while (pos > 0)
		{
			rra(a);
			pos--;
		}
	}
}

int	max_index(t_stack *a)
{
	int	max;
	int	i;

	max = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->values[i] > a->values[max])
			max = i;
		i++;
	}
	return (max);
}

void	max_to_top(t_stack *b)
{
	int	pos;

	pos = max_index(b);
	if (pos <= b->size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		pos = b->size - pos;
		while (pos > 0)
		{
			rrb(b);
			pos--;
		}
	}
}
