#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	(void)argv;
	if (argc < 3)
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
	a.size = 2;
	printf("%d  %d\n", a.values[0], a.values[1]);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	printf("a: size = %d, top = %d\n", a.size, a.values[0]);
	printf("b: size = %d, top = %d\n", b.size, b.values[0]);
	printf("a: size = %d\n", a.size);
	printf("b: size = %d\n, valuse = %d, %d\n", b.size, b.values[0], b.values[1]);
	free(a.values);
	free(b.values);
	return (0);
}