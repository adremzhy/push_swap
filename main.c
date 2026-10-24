#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;

	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || !args[0])
		error_free(NULL, NULL, args);
	if (!init_stacks(&a, &b, count_args(args))
		|| !parse_and_fill_stack(&a, args))
	{
		if (argc == 2)
			free_args(args);
		error_free(&a, &b, NULL);
	}
	if (argc == 2)
		free_args(args);
	sort_small(&a);
	free(a.values);
	free(b.values);
	return (0);
}
