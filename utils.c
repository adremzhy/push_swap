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

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count] != NULL)
	{
		count++;
	}
	return (count);
}

int	init_stacks(t_stack *a, t_stack *b, int count)
{
	a->values = NULL;
	a->size = 0;
	b->values = NULL;
	b->size = 0;
	a->values = malloc(sizeof(int) * count);
	if (!a->values)
		return (0);
	b->values = malloc(sizeof(int) * count);
	if (!b->values)
		return (0);
	return (1);
}
