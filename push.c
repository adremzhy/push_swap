#include "push_swap.h"

void push(t_stack *src, t_stack *dest)
{
	int i;

	if (src->size == 0)
		return ;
	i = dest->size;
	while (i > 0)
	{
		dest->values[i] = dest->values[i - 1];
		i--;
	}
	dest->values[0] = src->values[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->values[i] = src->values[i + 1];
		i++;
	}
	src->size--;
	dest->size++;
}