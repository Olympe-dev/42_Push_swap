/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 09:10:32 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/28 09:10:49 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sentence(long *tab_a, long *tab_b, int ac)
{
	if (ac > 1 && (ft_is_sorted(tab_a, ac) == 0 || ft_is_empty(tab_b, ac) == 0))
		write(1, "KO\n", 3);
	else if (ac > 1 && (ft_is_sorted(tab_a, ac) || ft_is_empty(tab_b, ac)))
		write(1, "OK\n", 3);
}

void	ft_finally(long *tab_a, long *tab_b, char **tab_instr, int ac)
{
	ft_apply(tab_a, tab_b, tab_instr, ac);
	ft_sentence(tab_a, tab_b, ac);
}

void	ft_free(long *tab_a, long *tab_b, char *instr, char **tab_instr)
{
	int	i;

	free(tab_a);
	free(tab_b);
	free(instr);
	i = 0;
	while (tab_instr[i])
	{
		free(tab_instr[i]);
		i++;
	}
	free(tab_instr);
}
