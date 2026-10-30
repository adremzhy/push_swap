/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_names.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:47:28 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:20:06 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	print_op(stack_a, op_ra, "ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	print_op(stack_b, op_rb, "rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	print_op(stack_a, op_rr, "rr\n");
}

void	print_op(t_stack *stack, t_op op, char *name)
{
	bench_record(stack->bench, op);
	ft_putstr_fd(name, 1);
}
