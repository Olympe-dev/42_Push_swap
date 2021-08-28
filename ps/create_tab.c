/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:14:59 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 09:00:08 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	long	res;
	int		signe;
	int		i;

	i = 0;
	signe = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = -1;
		while (s[i] == '-' || s[i] == '+')
			i++;
	}
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * signe);
}

void	ft_fill_arg(long *tab, char **av)
{
	int	i;

	i = 0;
	while (av[i + 1])
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

void	ft_fill_neutral(long *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		tab[i] = -2147483649;
		i++;
	}
}
