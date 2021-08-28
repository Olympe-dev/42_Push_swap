/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:58:32 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 08:58:34 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallest_tab(long *tab_a, long *tab_b, int size)
{
	if (tab_a[0] < tab_a[1] && tab_a[1] > tab_a[2] && tab_a[0] < tab_a[2])
	{
		ft_swap(tab_a, tab_b, "sa", size);
		ft_rotate(tab_a, tab_b, "ra", size);
	}
	else if (tab_a[0] > tab_a[1] && tab_a[1] < tab_a[2] && tab_a[0] < tab_a[2])
		ft_swap(tab_a, tab_b, "sa", size);
	else if (tab_a[0] < tab_a[1] && tab_a[1] > tab_a[2] && tab_a[0] > tab_a[2])
		ft_rrotate(tab_a, tab_b, "rra", size);
	else if (tab_a[0] > tab_a[1] && tab_a[1] < tab_a[2] && tab_a[0] > tab_a[2])
		ft_rotate(tab_a, tab_b, "ra", size);
	else if (tab_a[0] > tab_a[1] && tab_a[1] > tab_a[2] && tab_a[0] > tab_a[2])
	{
		ft_swap(tab_a, tab_b, "sa", size);
		ft_rrotate(tab_a, tab_b, "rra", size);
	}
}

void	ft_put_on_top_a(long *tab_a, long *tab_b, int size, int index_to_move)
{
	if ((size - index_to_move) > index_to_move)
	{
		while (index_to_move > 0)
		{
			ft_rotate(tab_a, tab_b, "ra", size);
			index_to_move--;
		}
	}
	else
	{
		while (index_to_move < size)
		{
			ft_rrotate(tab_a, tab_b, "rra", size);
			index_to_move++;
		}
	}
}

void	ft_special_case_min_max(long *tab_a, long *tab_b, char *minmax, int ac)
{
	if (ft_strcmp(minmax, "mini") == 0)
	{
		ft_push(tab_a, tab_b, "pa", ac);
		ft_push(tab_a, tab_b, "pa", ac);
		ft_rotate(tab_a, tab_b, "ra", ft_get_size(tab_a, ac));
	}
	else if (ft_strcmp(minmax, "max") == 0)
	{
		ft_push(tab_a, tab_b, "pa", ac);
		ft_rotate(tab_a, tab_b, "ra", ft_get_size(tab_a, ac));
		ft_push(tab_a, tab_b, "pa", ac);
	}
}

void	ft_before_anything(long *tab_a, long *tab_b, int ac)
{
	long	mini;
	long	max;

	max = ft_get_max(tab_a, ac);
	mini = tab_a[ft_get_index_mini(tab_a, ac)];
	ft_push(tab_b, tab_a, "pb", ac);
	if (ac == 6)
		ft_push(tab_b, tab_a, "pb", ac);
	if (ft_is_sorted(tab_a, ac) == 0)
		ft_smallest_tab(tab_a, tab_b, ft_get_size(tab_a, ac));
	if (tab_b[0] == mini && tab_b[1] == max)
		ft_special_case_min_max(tab_a, tab_b, "mini", ac);
	else if (tab_b[0] == max && tab_b[1] == mini)
		ft_special_case_min_max(tab_a, tab_b, "max", ac);
}

void	ft_small_tab(long *tab_a, long *tab_b, int ac)
{
	long	up_diff;
	long	down_diff;
	long	max;
	long	mini;

	max = ft_get_max(tab_a, ac);
	mini = tab_a[ft_get_index_mini(tab_a, ac)];
	ft_before_anything(tab_a, tab_b, ac);
	while (ft_get_size(tab_b, ac))
	{
		up_diff = ft_get_diff(tab_a, tab_b, "up", ac);
		down_diff = ft_get_diff(tab_a, tab_b, "down", ac);
		if (up_diff < down_diff && tab_b[0] != max && tab_b[0] != mini)
			while (tab_a[0] - tab_b[0] < 0)
				ft_rotate(tab_a, tab_b, "ra", ft_get_size(tab_a, ac));
		else if (up_diff >= down_diff && tab_b[0] != max && tab_b[0] != mini)
			while (tab_a[ft_get_size(tab_a, ac) - 1] - tab_b[0] > 0)
				ft_rrotate(tab_a, tab_b, "rra", ft_get_size(tab_a, ac));
		else if (tab_b[0] == max || tab_b[0] == mini)
			ft_put_on_top_a(tab_a, tab_b,
				ft_get_size(tab_a, ac), ft_get_index_mini(tab_a, ac));
		ft_push(tab_a, tab_b, "pa", ac);
	}
	ft_put_on_top_a(tab_a, tab_b,
		ft_get_size(tab_a, ac), ft_get_index_mini(tab_a, ac));
}
