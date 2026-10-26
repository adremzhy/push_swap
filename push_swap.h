#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# define STRAT_SIMPLE 1
# define STRAT_MEDIUM 2
# define STRAT_COMPLEX 3
# define STRAT_ADAPTIVE 4

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

// utils
void	free_args(char **args);
void	free_stack(t_stack *stack);
void	error_free(t_stack *stack_a, t_stack *stack_b, char **args);
int		get_chunk_size(int n);

// sort utils
int		is_sorted(t_stack *stack);
int		min_index(t_stack *a);
int		max_index(t_stack *a);
void	min_to_top(t_stack *a);
void	max_to_top(t_stack *b);
void	sort_dispatch(t_stack *a, t_stack *b, int strategy)


// sort small
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four_five(t_stack *a, t_stack *b);
void	sort_simple(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

// sort adaptive & utils
int		get_strategy(char *arg);
double	disorder(t_stack *stack);
void	sort_adaptive(t_stack *a, t_stack *b);

// ranks for medium sort
int	get_rank(t_stack *a, int index);
int	*create_ranks(t_stack *a);
int	set_ranks(t_stack *a);

// sort medium
int		find_below(t_stack *a, int limit);
void	push_chunk(t_stack *a, t_stack *b, int limit);
void	sort_medium(t_stack *a, t_stack *b, int	chunk_size);

// sort complex radix
int		get_bits(int max_rank);
void	radix_pass(t_stack *a, t_stack *b, int bit);
void	sort_complex(t_stack *a, t_stack *b);

// operation calls
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif