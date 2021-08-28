/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:59:15 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 08:58:39 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_get_size(long *tab, int ac)
{
	int	i;

	i = 0;
	while (tab[i] != -2147483649 && i < ac - 2)
		i++;
	if (tab[i] == -2147483649)
		return (i);
	return (i + 1);
}

int	ft_get_index_mini(long *tab, int ac)
{
	int		i;
	int		index_mini;
	long	mini;
	int		size;

	i = 0;
	size = ft_get_size(tab, ac);
	mini = 2147483648;
	while (i < size)
	{
		if (tab[i] < mini && tab[i] != -2147483649)
		{
			mini = tab[i];
			index_mini = i;
		}
		i++;
	}
	return (index_mini);
}

long	ft_get_max(long *tab, int ac)
{
	int		i;
	int		size;
	long	max;

	i = 0;
	size = ft_get_size(tab, ac);
	max = -2147483649;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

long	ft_get_diff(long *tab_a, long *tab_b, char *updown, int ac)
{
	long	diff;

	diff = 0;
	if (ft_strcmp(updown, "up") == 0)
	{
		diff = tab_a[0] - tab_b[0];
		if (diff < 0)
			diff = -diff;
	}
	else if (ft_strcmp(updown, "down") == 0)
	{
		diff = tab_a[ft_get_size(tab_a, ac) - 1] - tab_b[0];
		if (diff < 0)
			diff = -diff;
	}
	return (diff);
}
