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

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->values[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[i] = tmp;
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;
	
	if (stack->size < 2)
		return ;
	tmp = stack->values[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = tmp;
}