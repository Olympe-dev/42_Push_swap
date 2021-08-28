/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:15:27 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 09:00:29 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_tab(long *tab, int size)
{
	long	to_move;
	int		i;

	to_move = tab[0];
	i = 0;
	while (i + 1 < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = to_move;
}

void	ft_rotate(long *tab_a, long *tab_b, char *instruction, int size)
{
	if (ft_strcmp(instruction, "ra") == 0 || ft_strcmp(instruction, "rr") == 0)
		ft_rotate_tab(tab_a, size);
	else if (ft_strcmp(instruction, "rb") == 0
		|| ft_strcmp(instruction, "rr") == 0)
		ft_rotate_tab(tab_b, size);
	if (ft_strcmp(instruction, "ra") == 0)
		write(1, "ra\n", 3);
	else if (ft_strcmp(instruction, "rb") == 0)
		write(1, "rb\n", 3);
	else if (ft_strcmp(instruction, "rr") == 0)
		write(1, "rr\n", 3);
}

void	ft_rrotate_tab(long *tab, int size)
{
	long	to_move;
	int		i;

	to_move = tab[size - 1];
	i = size - 1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = to_move;
}

void	ft_rrotate(long *tab_a, long *tab_b, char *instruction, int size)
{
	if (ft_strcmp(instruction, "rra") == 0
		|| ft_strcmp(instruction, "rrr") == 0)
		ft_rrotate_tab(tab_a, size);
	if (ft_strcmp(instruction, "rrb") == 0
		|| ft_strcmp(instruction, "rrr") == 0)
		ft_rrotate_tab(tab_b, size);
	if (ft_strcmp(instruction, "rra") == 0)
		write(1, "rra\n", 4);
	if (ft_strcmp(instruction, "rrb") == 0)
		write(1, "rrb\n", 4);
	if (ft_strcmp(instruction, "rrr") == 0)
		write(1, "rrr\n", 4);
}
