/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:00:20 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/28 15:17:28 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *stack)
{
	int		i;
	int		j;
	double	count;
	int		temp;
	double	pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	i = 0;
	count = 0;
	temp = stack->size;
	pairs = (double)temp * (temp - 1) / 2.0;
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

void	bench_print_disorder(t_bench *bench)
{
	long	scaled;

	scaled = (long)(bench->initial_disorder * 10000 + 0.5);
	ft_putstr_fd("disorder: ", 2);
	bench_printlong(scaled / 100);
	ft_putchar_fd('.', 2);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', 2);
	bench_printlong(scaled % 100);
	ft_putstr_fd("%\n", 2);
}

void	bench_prints_counts(t_bench *bench)
{
	int		op_counts;
	char	*op_names[op_counts];
	int		i;

	op_counts = 11;
	op_names[op_pa] = "pa";
	op_names[op_pb] = "pb";
	op_names[op_ra] = "ra";
	op_names[op_rb] = "rb";
	op_names[op_rr] = "rr";
	op_names[op_rra] = "rra";
	op_names[op_rrb] = "rrb";
	op_names[op_rrr] = "rrr";
	op_names[op_sa] = "sa";
	op_names[op_sb] = "sb";
	op_names[op_ss] = "ss";
	i = 0;
	while (i < op_counts)
	{
		ft_putstr_fd(op_names[i], 2);
		ft_putstr_fd(": ", 2);
		bench_printlong(bench->counts[i]);
		ft_putchar_fd('\n', 2);
		i++;
	}
}
