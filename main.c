#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.values = NULL;
	a.size = 0;
	b.values = NULL;
	b.size = 0;
	a.values = malloc(sizeof(int) * (argc - 1));
	if (a.values == NULL)
		error_free(&a, &b, NULL);
	b.values = malloc(sizeof(int) * (argc - 1));
	if (b.values == NULL)
		error_free(&a, &b, NULL);
	if (!parse_and_fill_stack(&a, argv + 1))
		error_free(&a, &b, NULL);
	free(a.values);
	free(b.values);
	return (0);
}
