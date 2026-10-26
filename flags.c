#include "push_swap.h"

int	get_strategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (STRAT_SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (STRAT_MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (STRAT_COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (STRAT_ADAPTIVE);
	return (0);
}