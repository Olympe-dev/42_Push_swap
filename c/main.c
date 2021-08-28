/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:14:59 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 14:02:42 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_fill_str_instr(char *instr, char *tmp)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(0, tmp, 3);
		tmp[ret] = '\0';
		instr = ft_strjoin(instr, tmp);
	}
	return (instr);
}

int	main(int ac, char **av)
{
	long	*tab_a;
	long	*tab_b;
	char	tmp[4];
	char	*instr;
	char	**tab_instr;

	if (ft_check(ac, av) == -1)
		return (-1);
	tab_a = ft_fill_arg(av, ac);
	if (tab_a == 0)
		return (0);
	if (ft_check_int_first(tab_a, ac) == -1)
		return (-1);
	tab_b = ft_fill_neutral(ac);
	if (tab_b == 0)
		return (0);
	instr = NULL;
	instr = ft_fill_str_instr(instr, tmp);
	tab_instr = ft_split(instr);
	if (ft_pre_analysis(tab_a, tab_b, instr, tab_instr) == -1)
		return (-1);
	ft_finally(tab_a, tab_b, tab_instr, ac);
	ft_free(tab_a, tab_b, instr, tab_instr);
	return (0);
}
