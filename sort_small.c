#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->values[0] > a->values[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->values[0] > a->values[1]
		&& a->values[0] > a->values[2])
	{
		ra(a);
	}
	else if (a->values[1] > a->values[0]
		&& a->values[1] > a->values[2])
	{
		rra(a);
	}
	if (a->values[0] > a->values[1])
		sa(a);
}

void	sort_small(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
}