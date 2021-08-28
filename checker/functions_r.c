/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:15:27 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 14:00:14 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_tab(long *tab, int ac)
{
	long	to_move;
	int		i;
	int		size;

	to_move = tab[0];
	i = 0;
	size = ft_get_size(tab, ac);
	while (i + 1 < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = to_move;
}

void	ft_rotate(long *tab_a, long *tab_b, char *instruction, int ac)
{
	if (ft_strcmp(instruction, "ra") == 0 || ft_strcmp(instruction, "rr") == 0)
		ft_rotate_tab(tab_a, ac);
	else if (ft_strcmp(instruction, "rb") == 0
		|| ft_strcmp(instruction, "rr") == 0)
		ft_rotate_tab(tab_b, ac);
}

void	ft_rrotate_tab(long *tab, int ac)
{
	long	to_move;
	int		i;
	int		size;

	size = ft_get_size(tab, ac);
	to_move = tab[size - 1];
	i = size - 1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = to_move;
}

void	ft_rrotate(long *tab_a, long *tab_b, char *instruction, int ac)
{
	if (ft_strcmp(instruction, "rra") == 0
		|| ft_strcmp(instruction, "rrr") == 0)
		ft_rrotate_tab(tab_a, ac);
	if (ft_strcmp(instruction, "rrb") == 0
		|| ft_strcmp(instruction, "rrr") == 0)
		ft_rrotate_tab(tab_b, ac);
}
