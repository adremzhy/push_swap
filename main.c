#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	if (argc < 2)
		return (0);
	a.values = NULL;
	a.size = 0;
	b.values = NULL;
	b.size = 0;
	a.values = malloc(sizeof(int) * (argc - 1));
	if (a.values == NULL)
		return (1);
	b.values = malloc(sizeof(int) * (argc - 1));
	if (b.values == NULL)
	{
		free(a.values);
		return (1);
	}
	free(a.values);
	free(b.values);
	return (0);
}