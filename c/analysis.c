/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 09:07:04 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/28 09:07:54 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_analysis(char **tab_instr)
{
	int	i;

	i = 0;
	while (tab_instr[i])
	{
		if ((ft_strcmp(tab_instr[i], "sa") != 0)
			&& (ft_strcmp(tab_instr[i], "sb") != 0)
			&& (ft_strcmp(tab_instr[i], "pa") != 0)
			&& (ft_strcmp(tab_instr[i], "pb") != 0)
			&& (ft_strcmp(tab_instr[i], "ra") != 0)
			&& (ft_strcmp(tab_instr[i], "rb") != 0)
			&& (ft_strcmp(tab_instr[i], "rr") != 0)
			&& (ft_strcmp(tab_instr[i], "rra") != 0)
			&& (ft_strcmp(tab_instr[i], "rrb") != 0)
			&& (ft_strcmp(tab_instr[i], "rrr") != 0))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_pre_analysis(long *tab_a, long *tab_b, char *instr, char **tab_instr)
{
	if (ft_analysis(tab_instr) == 0)
	{
		ft_free(tab_a, tab_b, instr, tab_instr);
		return (-1);
	}
	return (0);
}
