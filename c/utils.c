/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:59:15 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 14:22:00 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_get_size(long *tab, int ac)
{
	int	i;

	i = 0;
	while (tab[i] != -2147483649 && i < ac - 2)
		i++;
	if (tab[i] == -2147483649)
		return (i);
	return (i + 1);
}

int	ft_is_sorted(long *tab, int ac)
{
	int	i;
	int	size;

	i = 0;
	size = ft_get_size(tab, ac);
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_empty(long *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 2)
	{
		if (tab[i] != -2147483649)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
