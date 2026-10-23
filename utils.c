/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:41:12 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/21 19:46:13 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->values);
	stack->values = NULL;
	stack->size = 0;
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	error_free(t_stack *stack_a, t_stack *stack_b, char **args)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (args)
		free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}
