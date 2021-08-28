/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:14:59 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 15:32:32 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_tab(long *tab_a, long *tab_b, int ac, double divide)
{
	long	i;
	long	diff;

	i = tab_a[ft_get_index_mini(tab_a, ac)];
	diff = ft_get_diff_numbers(tab_a, ac, divide);
	while (ft_get_size(tab_a, ac))
	{
		while (ft_there_is(tab_a, ac, i, i + diff))
		{
			ft_right_rotate_a(tab_a, ac, i, diff);
			ft_put_b_right(tab_a, tab_b, ac);
			ft_push(tab_b, tab_a, "pb", ac);
		}
		i += diff;
	}
	ft_repush_on_a(tab_a, tab_b, ac);
}

void	ft_which_size(long *tab_a, long *tab_b, int ac)
{
	int	size_a;

	size_a = ft_get_size(tab_a, ac);
	if (size_a == 2 && tab_a[0] > tab_a[1])
		ft_swap(tab_a, tab_b, "sa", size_a);
	else if (size_a == 3)
		ft_smallest_tab(tab_a, tab_b, size_a);
	else if (size_a <= 5)
		ft_small_tab(tab_a, tab_b, ac);
	else if (size_a <= 100)
		ft_big_tab(tab_a, tab_b, ac, 5);
	else if (size_a <= 500)
		ft_big_tab(tab_a, tab_b, ac, 12.5);
}

int	main(int ac, char **av)
{
	long	*tab_a;
	long	*tab_b;

	if (ac < 2)
		return (-1);
	if (ft_check_char(av) == 0)
		return (-1);
	tab_a = (long *)malloc(sizeof(long) * (ac - 1));
	if (tab_a == 0)
		return (0);
	ft_fill_arg(tab_a, av);
	if (ft_check_int(tab_a, ac) == 0)
		return (-1);
	tab_b = (long *)malloc(sizeof(long) * (ac - 1));
	if (tab_b == 0)
		return (0);
	ft_fill_neutral(tab_b, ac);
	if (ft_is_upside_down(tab_a, ac) && ft_get_size(tab_a, ac) > 5)
		ft_put_back_up(tab_a, tab_b, ac);
	else if (ft_get_size(tab_a, ac) > 1 && ft_is_sorted(tab_a, ac) == 0)
		ft_which_size(tab_a, tab_b, ac);
	free(tab_a);
	free(tab_b);
	return (0);
}
