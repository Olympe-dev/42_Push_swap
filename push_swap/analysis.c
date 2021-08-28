/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:57:35 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 08:57:43 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(long *tab, int ac)
{
	int	i;
	int	size;

	i = 0;
	size = ft_get_size(tab, ac);
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_upside_down(long *tab, int ac)
{
	int	i;
	int	size;

	i = 0;
	size = ft_get_size(tab, ac);
	while (i + 1 < size)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_back_up(long *tab_a, long *tab_b, int ac)
{
	while (ft_get_size(tab_a, ac))
	{
		ft_rrotate(tab_a, tab_b, "rra", ft_get_size(tab_a, ac));
		ft_push(tab_b, tab_a, "pb", ac);
	}
	while (ft_get_size(tab_b, ac))
		ft_push(tab_a, tab_b, "pa", ac);
}
