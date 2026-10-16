/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:41:12 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/16 18:26:49 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
	t_stack *temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void free_args(char **args)
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

void error_free(t_stack **stack_a, char **args)
{
	free_stack(stack_a);
	if (args)
		free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atol(const char *nptr)
{
	long	i;
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if(!stack || !new_node)
		return ;
	if(*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
}
