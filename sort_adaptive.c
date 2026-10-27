/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:25:00 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:25:02 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b)
{
	double	d;

	d = disorder(a);
	if (d < 0.2)
	{
		a->bench->strategy = STRAT_SIMPLE;
		sort_simple(a, b);
	}
	else if (d < 0.5)
	{
		a->bench->strategy = STRAT_MEDIUM;
		sort_medium(a, b, get_chunk_size(a->size));
	}
	else
	{
		a->bench->strategy = STRAT_COMPLEX;
		sort_complex(a, b);
	}
}
