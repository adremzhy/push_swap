#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int *values;
	struct s_stack	*next; //--?
} t_stack;

void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	free_args(char **args);
void 	free_stack(t_stack **stack);
void	error_free(t_stack **stack_a, char **args);
int		ft_atol(const char *nptr);
void	stack_add_end(t_stack **stack, t_stack *new_node);

#endif