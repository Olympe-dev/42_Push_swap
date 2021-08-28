/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:58:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 08:58:45 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_get_index_first(long *tab, int ac, long from, long to)
{
	long	size;
	long	i;

	i = 0;
	size = ft_get_size(tab, ac);
	while (i < size)
	{
		if (tab[i] >= from && tab[i] <= to)
			return (i);
		i++;
	}
	return (-2147483649);
}

long	ft_get_index_second(long *tab, int ac, long from, long to)
{
	long	size;

	size = ft_get_size(tab, ac);
	while (size > 0)
	{
		if (tab[size - 1] >= from && tab[size - 1] <= to)
			return (size - 1);
		size--;
	}
	return (-2147483649);
}

int	ft_there_is(long *tab, int ac, long from, long to)
{
	int	size;
	int	i;

	size = ft_get_size(tab, ac);
	i = 0;
	while (i < size)
	{
		if (tab[i] >= from && tab[i] <= to)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_index_max(long *tab, int ac)
{
	int		i;
	int		index_max;
	long	max;
	int		size;

	i = 0;
	size = ft_get_size(tab, ac);
	max = -2147483649;
	while (i < size)
	{
		if (tab[i] > max && tab[i] != -2147483649)
		{
			max = tab[i];
			index_max = i;
		}
		i++;
	}
	return (index_max);
}

long	ft_get_diff_numbers(long *tab, int ac, int divide)
{
	long	diff;
	long	mini;
	long	max;

	mini = tab[ft_get_index_mini(tab, ac)];
	max = tab[ft_get_index_max(tab, ac)];
	diff = (max - mini) / divide;
	return (diff);
}
