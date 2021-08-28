/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:14:59 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 14:18:32 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check(int ac, char **av)
{
	if (ac < 2)
		return (-1);
	if (ft_check_char(av) == 0)
		return (-1);
	return (0);
}

int	ft_check_char(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_int(long *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (ft_check_double(tab, ac) == 0)
		return (0);
	return (1);
}

int	ft_check_int_first(long *tab_a, int ac)
{
	if (ft_check_int(tab_a, ac) == 0)
	{
		free(tab_a);
		return (-1);
	}
	return (0);
}

int	ft_check_double(long *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
