#include "push_swap.h"

int	get_rank(t_stack *a, int index)
{
	int	i;
	int	rank;

	rank = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->values[i] < a->values[index])
			rank++;
		i++;
	}
	return (rank);
}

int	*create_ranks(t_stack *a)
{
	int	i;
	int	*ranks;

	ranks = malloc(sizeof(int) * a->size);
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		ranks[i] = get_rank(a, i);
		i++;
	}
	return (ranks);
}

int	set_ranks(t_stack *a)
{
	int	*ranks;

	ranks = create_ranks(a);
	if (!ranks)
		return (0);
	free(a->values);
	a->values = ranks;
	return (1);
}
