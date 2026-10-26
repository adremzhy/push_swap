#include "push_swap.h"

void	sort_dispatch(t_stack *a, t_stack *b, int strategy)
{
	if (a->size <= 5)
	{
		sort_small(a, b);
		return ;
	}
	if (strategy == STRAT_SIMPLE)
		sort_simple(a, b);
	else if (strategy == STRAT_MEDIUM)
		sort_medium(a, b, get_chunk_size(a->size));
	else if (strategy == STRAT_COMPLEX)
		sort_complex(a, b);
	else if (strategy == STRAT_ADAPTIVE)
		sort_adaptive(a, b);
}
