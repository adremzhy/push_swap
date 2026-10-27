/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuskov <nhuskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:26:45 by nhuskov           #+#    #+#             */
/*   Updated: 2026/10/27 16:26:48 by nhuskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_flag_bench(char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (1);
	return (0);
}
