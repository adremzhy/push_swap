#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;
	
	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}