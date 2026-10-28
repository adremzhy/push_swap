/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:25:06 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/28 15:40:43 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_stack *a, t_stack *b, int strategy)
{
	a->bench->strategy = strategy;
	if (strategy == STRAT_SIMPLE)
		sort_simple(a, b);
	else if (strategy == STRAT_MEDIUM)
		sort_medium(a, b, get_chunk_size(a->size));
	else if (strategy == STRAT_COMPLEX)
		sort_complex(a, b);
	else if (strategy == STRAT_ADAPTIVE)
		sort_adaptive(a, b);
}
