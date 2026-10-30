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
	print_op(stack_a, op_rrr, "rrr\n");
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	print_op(stack_a, op_rra, "rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	print_op(stack_b, op_rrb, "rrb\n");
}
