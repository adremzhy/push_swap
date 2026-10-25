#include "push_swap.h"

void	sort_simple(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	while (a->size > 0)
	{
		min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}