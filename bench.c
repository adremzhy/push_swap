/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:28:39 by adremzhy          #+#    #+#             */
/*   Updated: 2026/10/28 15:28:40 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_initialize(t_bench *bench, int enbld)
{
	int	i;

	bench->enabled = enbld;
	bench->total = 0;
	i = 0;
	while (i < op_counts)
	{
		bench->counts[i] = 0;
		i++;
	}
}

void	bench_record(t_bench *bench, t_op op_index)
{
	if (!bench)
		return ;
	bench->total++;
	bench->counts[op_index]++;
}

void	bench_setup(t_stack *a, t_stack *b, t_bench *bench)
{
	a->bench = bench;
	b->bench = bench;
}

void	bench_printlong(long number, int fd)
{
	if (number >= 10)
		bench_printlong(number / 10, fd);
	ft_putchar_fd(number % 10 + '0', fd);
}

void	bench_print(t_bench *bench)
{
	if (bench->enabled == 0)
		return ;
	bench_print_disorder(bench);
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (bench->selected_strategy == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptive  /  ", 2);
	else if (bench->selected_strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple  /  ", 2);
	else if (bench->selected_strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium  /  ", 2);
	else if (bench->selected_strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex  /  ", 2);
	if (bench->strategy == STRAT_SIMPLE)
		ft_putstr_fd("simple O(n^2)\n", 2);
	else if (bench->strategy == STRAT_MEDIUM)
		ft_putstr_fd("medium O(n*sqrt(n))\n", 2);
	else if (bench->strategy == STRAT_COMPLEX)
		ft_putstr_fd("complex O(n*log(n))\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	bench_printlong(bench->total, 2);
	ft_putchar_fd('\n', 2);
	bench_prints_counts(bench);
	ft_putchar_fd('\n', 2);
}
