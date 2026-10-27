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
