/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes_swaps_names.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:39:14 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/21 19:54:20 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	print_op(stack_a, op_sa, "sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	print_op(stack_b, op_sb, "sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	print_op(stack_a, op_ss, "ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	print_op(stack_b, op_pa, "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	print_op(stack_a, op_pb, "pb\n");
}
