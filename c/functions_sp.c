/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:15:27 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 11:00:42 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_int(long *tab)
{
	long	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	ft_swap(long *tab_a, long *tab_b, char *instruction, int size)
{
	if (ft_strcmp(instruction, "sa") == 0 || ft_strcmp(instruction, "ss") == 0)
		if (size > 1)
			ft_swap_int(tab_a);
	if (ft_strcmp(instruction, "sb") == 0 || ft_strcmp(instruction, "ss") == 0)
		if (size > 1)
			ft_swap_int(tab_b);
}

void	ft_push(long *tab_to, long *tab_from, int ac)
{
	long	to_move;
	int		i;
	int		size_from;
	int		size_to;

	to_move = tab_from[0];
	size_from = ft_get_size(tab_from, ac);
	size_to = ft_get_size(tab_to, ac);
	i = 0;
	while (i + 1 < size_from)
	{
		tab_from[i] = tab_from[i + 1];
		i++;
	}
	tab_from[i] = -2147483649;
	while (size_to > 0)
	{
		tab_to[size_to] = tab_to[size_to - 1];
		size_to--;
	}
	tab_to[0] = to_move;
}
