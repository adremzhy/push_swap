#include "push_swap.h"

void	bench_initialize(t_bench *bench, int enbld)
{
	int i;

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
	bench_initialize(bench, 0);
	a->bench = bench;
	b->bench = bench;
}

void	bench_printlong(long number)
{
	if (number >= 10)
		bench_printlong(number / 10);
	ft_putchar_fd(number % 10 + '0', 2);
}

void	bench_print(t_bench *bench)
{
	if (bench->enabled == 0)
		return ;
	ft_putstr_fd("[bench]\n", 2);
	bench_print_disorder(bench);
	if (bench->strategy == STRAT_SIMPLE)
		ft_putstr_fd("strategy: simple O(n^2)\n", 2);
	else if (bench->strategy == STRAT_MEDIUM)
		ft_putstr_fd("strategy: medium O(n*sqrt(n))\n", 2);
	else if (bench->strategy == STRAT_COMPLEX)
		ft_putstr_fd("strategy: complex O(n*log(n))\n", 2);
	ft_putstr_fd("total: ", 2);
	bench_printlong(bench->total);
	ft_putchar_fd('\n', 2);
	bench_prints_counts(bench);
	ft_putchar_fd('\n', 2);
}