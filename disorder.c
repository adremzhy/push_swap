/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:00:20 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/21 20:32:28 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *stack)
{
	int		i;
	int		j;
	int		count;
	int		temp;
	double	pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	i = 0;
	count = 0;
	temp = stack->size;
	pairs = (temp * (temp - 1)) / 2.0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				count++;
			j++;
		}
		i++;
	}
	return (count / pairs);
}
