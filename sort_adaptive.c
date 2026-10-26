#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b)
{
	double	d;

	d = disorder(a);
	if (d < 0.2)
		sort_simple(a, b);
	else if (d < 0.5)
		sort_medium(a, b, get_chunk_size(a->size));
	else
		sort_complex(a, b);
}
