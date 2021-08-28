/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:14:59 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 13:59:59 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

long	*ft_fill_arg(char **av, int ac)
{
	int		i;
	long	*tab_a;

	tab_a = (long *)malloc(sizeof(long) * (ac - 1));
	if (tab_a == 0)
		return (0);
	i = 0;
	while (av[i + 1])
	{
		tab_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab_a);
}

long	*ft_fill_neutral(int ac)
{
	int		i;
	long	*tab_b;

	tab_b = (long *)malloc(sizeof(long) * (ac - 1));
	if (tab_b == 0)
		return (0);
	i = 0;
	while (i < ac - 1)
	{
		tab_b[i] = -2147483649;
		i++;
	}
	return (tab_b);
}
