#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int *values;
} t_stack;

void	swap(t_stack *stack);
void push(t_stack *src, t_stack *dest);


#endif