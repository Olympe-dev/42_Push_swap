/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:41 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/28 09:10:04 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_apply_r(long *tab_a, long *tab_b, char *instr, int ac)
{
	if (ft_strcmp(instr, "ra") == 0)
		ft_rotate(tab_a, tab_b, "ra", ac);
	else if (ft_strcmp(instr, "rb") == 0)
		ft_rotate(tab_a, tab_b, "rb", ac);
	else if (ft_strcmp(instr, "rr") == 0)
		ft_rotate(tab_a, tab_b, "rr", ac);
	else if (ft_strcmp(instr, "rra") == 0)
		ft_rrotate(tab_a, tab_b, "rra", ac);
	else if (ft_strcmp(instr, "rrb") == 0)
		ft_rrotate(tab_a, tab_b, "rrb", ac);
	else if (ft_strcmp(instr, "rrr") == 0)
		ft_rrotate(tab_a, tab_b, "rrr", ac);
}

void	ft_apply_sp(long *tab_a, long *tab_b, char *instr, int ac)
{
	if (ft_strcmp(instr, "sa") == 0)
		ft_swap(tab_a, tab_b, "sa", ft_get_size(tab_a, ac));
	else if (ft_strcmp(instr, "sb") == 0)
		ft_swap(tab_a, tab_b, "sb", ft_get_size(tab_b, ac));
	else if (ft_strcmp(instr, "pa") == 0)
		ft_push(tab_a, tab_b, ac);
	else if (ft_strcmp(instr, "pb") == 0)
		ft_push(tab_b, tab_a, ac);
}

void	ft_apply(long *tab_a, long *tab_b, char **tab_ins, int ac)
{
	int	i;

	i = 0;
	while (tab_ins[i])
	{
		if ((ft_strcmp(tab_ins[i], "sa") == 0)
			|| (ft_strcmp(tab_ins[i], "sb") == 0)
			|| ((ft_strcmp(tab_ins[i], "pa") == 0) && tab_b[0] != -2147483649)
			|| ((ft_strcmp(tab_ins[i], "pb") == 0) && tab_a[0] != -2147483649))
			ft_apply_sp(tab_a, tab_b, tab_ins[i], ac);
		else if ((ft_strcmp(tab_ins[i], "ra") == 0)
			|| (ft_strcmp(tab_ins[i], "rb") == 0)
			|| (ft_strcmp(tab_ins[i], "rr") == 0)
			|| (ft_strcmp(tab_ins[i], "rra") == 0)
			|| (ft_strcmp(tab_ins[i], "rrb") == 0)
			|| (ft_strcmp(tab_ins[i], "rrr") == 0))
			ft_apply_r(tab_a, tab_b, tab_ins[i], ac);
		i++;
	}
}
