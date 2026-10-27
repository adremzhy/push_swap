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

int	run_prog(int argc, char **argv, int strategy)
{
	t_stack	a;
	t_stack	b;
	char	**args;

	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || !args[0])
		error_free(NULL, NULL, args);
	if (!init_stacks(&a, &b, count_args(args))
		|| !parse_and_fill_stack(&a, args) || !set_ranks(&a))
	{
		if (argc == 2)
			free_args(args);
		error_free(&a, &b, NULL);
	}
	if (argc == 2)
		free_args(args);
	sort_dispatch(&a, &b, strategy);
	free(a.values);
	free(b.values);
	return (0);
}

int	main(int argc, char **argv)
{
	int	strategy;

	if (argc < 2)
		return (0);
	strategy = get_strategy(argv[1]);
	if (strategy)
	{
		argv++;
		argc--;
	}
	else
		strategy = STRAT_ADAPTIVE;
	return (run_prog(argc, argv, strategy));
}
