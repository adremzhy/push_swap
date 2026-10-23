#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	*values;
}	t_stack;

// basic operations functions
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// parsing functions
int		parse_and_fill_stack(t_stack *stack_a, char **args);
int		parse_int(const char *str, int *out);
int		has_duplicate(t_stack *stack, int num);
int		is_valid_syntax(char *str);

int		init_stacks(t_stack *a, t_stack *b, int count);
int		count_args(char **args);

void	free_args(char **args);
void	free_stack(t_stack *stack);
void	error_free(t_stack *stack_a, t_stack *stack_b, char **args);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif