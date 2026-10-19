#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	(void)argv;
	if (argc < 4)
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
	a.values[0] = 8;
	a.values[1] = 4;
	a.values[2] = 2;
	a.size = 3;
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	rotate(&a);
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	rotate(&a);
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	reverse_rotate(&a);
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	reverse_rotate(&a);
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	reverse_rotate(&a);
	printf("%d  %d  %d\n", a.values[0], a.values[1], a.values[2]);
	free(a.values);
	free(b.values);
	return (0);
}