/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_names1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:19:13 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:19:56 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	bench_record(stack_a->bench, op_rrr);
	write(1, "rrr\n", 4);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	bench_record(stack_a->bench, op_rra);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	bench_record(stack_b->bench, op_rrb);
	write(1, "rrb\n", 4);
}
