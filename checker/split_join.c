/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:18:55 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/24 14:22:38 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_bsn(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int	ft_count_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\0' && is_bsn(str[i]))
			i++;
		if (str[i] != '\0' && is_bsn(str[i]) == 0)
			count++;
		while (str[i] != '\0' && is_bsn(str[i]) == 0)
			i++;
	}
	return (count);
}

int	ft_str_s(char *str, int j)
{
	int	str_size;

	str_size = 0;
	while (str[j] != '\0' && (is_bsn(str[j]) == 0))
	{
		str_size++;
		j++;
	}
	return (str_size);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (ft_count_lines(str) + 1));
	if (tab == 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < ft_count_lines(str))
	{
		while (str[j] != '\0' && is_bsn(str[j]))
			j++;
		tab[i] = malloc(sizeof(char) * (ft_str_s(str, j) + 1));
		if (tab[i] == 0)
			return (0);
		k = 0;
		while (str[j] != '\0' && is_bsn(str[j]) == 0)
			tab[i][k++] = str[j++];
		tab[i][k] = '\0';
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_strjoin(char *ins, char *tmp)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (ins == 0 && tmp == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(ins) + ft_strlen(tmp) + 1));
	if (res == 0)
		return (0);
	i = -1;
	size = ft_strlen(ins);
	while (++i < size)
		res[i] = ins[i];
	j = 0;
	size = ft_strlen(tmp);
	while (j < size)
	{
		res[i] = tmp[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free (ins);
	return (res);
}
