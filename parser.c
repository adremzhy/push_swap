/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:35:38 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/21 19:45:48 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int num)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	parse_and_fill_stack(t_stack *stack_a, char **args)
{
	int	i;
	int	num;

	i = 0;
	while (args[i])
	{
		if (!parse_int(args[i], &num))
			return (0);
		if (has_duplicate(stack_a, num))
			return (0);
		stack_a->values[stack_a->size] = num;
		stack_a->size++;
		i++;
	}
	return (1);
}
int	parse_int(const char *str, int *out)
{
	int		i;
	int		sign;
	long	result;

	i = (str[0] == '-' || str[0] == '+');
	sign = 1;
	result = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}
