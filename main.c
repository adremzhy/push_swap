/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:26:40 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:26:41 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_prog(int argc, char **argv, int strategy, t_bench *bench)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	prepare_stacks(argc, argv, &a, &b);
	bench_setup(&a, &b, bench);
	bench->initial_disorder = disorder(&a);
	sort_dispatch(&a, &b, strategy);
	bench_print(bench);
	free(a.values);
	free(b.values);
	return (0);
}

void	prepare_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || !args[0])
		error_free(NULL, NULL, args);
	if (!init_stacks(a, b, count_args(args))
		|| !parse_and_fill_stack(a, args) || !set_ranks(a))
	{
		if (argc == 2)
			free_args(args);
		error_free(a, b, NULL);
	}
	if (argc == 2)
		free_args(args);
}

int	main(int argc, char **argv)
{
	int	strategy;
	int	bench_enbld;
	t_bench bench;

	bench_enbld = 0;
	if (argc < 2)
		return (0);
	strategy = STRAT_ADAPTIVE;
	while (argc > 1)
	{
		if (is_flag_bench(argv[1]))
			bench_enbld = 1;
		else if (get_strategy(argv[1]) != 0)
			strategy = get_strategy(argv[1]);
		else
			break ;
		argv++;
		argc--;
	}
	bench_initialize(&bench, bench_enbld);
	return (run_prog(argc, argv, strategy, &bench));
}
