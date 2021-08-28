/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:58:26 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 09:02:02 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_on_top_b(long *tab_a, long *tab_b, int size, int index_to_move)
{
	if ((size - index_to_move) > index_to_move)
	{
		while (index_to_move > 0)
		{
			ft_rotate(tab_a, tab_b, "rb", size);
			index_to_move--;
		}
	}
	else
	{
		while (index_to_move < size)
		{
			ft_rrotate(tab_a, tab_b, "rrb", size);
			index_to_move++;
		}
	}
}

void	ft_right_rotate_b(long *tab_a, long *tab_b, int index_closest, int ac)
{
	long	max;
	long	mini;
	int		size;

	max = ft_get_max(tab_b, ac);
	mini = tab_b[ft_get_index_mini(tab_b, ac)];
	size = ft_get_size(tab_b, ac);
	if (tab_a[0] == max || tab_a[0] == mini)
		ft_put_on_top_b(tab_a, tab_b, size, ft_get_index_mini(tab_b, ac));
	else if (index_closest <= size - index_closest + 1)
	{
		while (index_closest > 0)
		{
			ft_rotate(tab_a, tab_b, "rb", size);
			index_closest--;
		}
	}
	else
	{
		while (index_closest < size)
		{
			ft_rrotate(tab_a, tab_b, "rrb", size);
			index_closest++;
		}
	}
}

void	ft_put_b_right(long *tab_a, long *tab_b, int ac)
{
	int		index_closest;
	long	diff;
	int		i;
	int		size;

	i = 0;
	size = ft_get_size(tab_b, ac);
	index_closest = 2147483647;
	diff = 2147483649;
	while (i < size)
	{
		if (tab_a[0] - tab_b[i] < diff)
		{
			diff = tab_a[0] - tab_b[i];
			index_closest = i;
		}
		i++;
	}
	ft_right_rotate_b(tab_a, tab_b, index_closest, ac);
}

void	ft_repush_on_a(long *tab_a, long *tab_b, int ac)
{
	int	size;

	while (ft_get_size(tab_b, ac))
	{
		size = ft_get_size(tab_b, ac);
		ft_put_on_top_b(tab_a, tab_b, size, ft_get_index_max(tab_b, ac));
		ft_push(tab_a, tab_b, "pa", ac);
	}
}

void	ft_right_rotate_a(long *tab_a, int ac, long i, long diff)
{
	long	i_first;
	long	i_second;

	i_first = ft_get_index_first(tab_a, ac, i, i + diff);
	i_second = ft_get_index_second(tab_a, ac, i, i + diff);
	if (i_first <= ft_get_size(tab_a, ac) - i_second + 1 && i_first > 0)
	{
		while (i_first > 0)
		{
			ft_rotate(tab_a, tab_a, "ra", ft_get_size(tab_a, ac));
			i_first--;
		}
	}
	else if (i_first > ft_get_size(tab_a, ac) - i_second + 1 && i_first > 0)
	{
		while (i_second < ft_get_size(tab_a, ac))
		{
			ft_rrotate(tab_a, tab_a, "rra", ft_get_size(tab_a, ac));
			i_second++;
		}
	}
}
