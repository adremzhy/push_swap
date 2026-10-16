/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:35:38 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/16 18:26:50 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_syntax(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == "+" || str[i] == "-") && str[i+1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return(1);
}

int	has_duplicate(t_stack *stack, int num)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->values == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	parse_and_fill_stack(t_stack **stack_a, char **args)
{
	long	num;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_syntax(args[i]))
			error_free(stack_a, args);
		num = ft_atol(args[i]);
		if (num > 2147483647 || num < -2147483648)
			error_free(stack_a, args);
		if (has_duplicate(*stack_a, (int)num))
			error_free(stack_a, args);
		stack_add_end(stack_a, stack_new((int)num));
		i++;
	}
}
