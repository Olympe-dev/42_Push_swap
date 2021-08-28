/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:45:36 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/23 15:28:01 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		ft_is_sorted(long *tab, int ac);
int		ft_is_upside_down(long *tab, int ac);
void	ft_put_back_up(long *tab_a, long *tab_b, int ac);
int		ft_check_char(char **av);
int		ft_check_int(long *tab, int ac);
int		ft_check_double(long *tab, int ac);
long	ft_atoi(char *s);
void	ft_fill_arg(long *tab, char **av);
void	ft_fill_neutral(long *tab, int ac);
void	ft_rotate_tab(long *tab, int size);
void	ft_rotate(long *tab_a, long *tab_b, char *instruction, int size);
void	ft_rrotate_tab(long *tab, int size);
void	ft_rrotate(long *tab_a, long *tab_b, char *instruction, int size);
void	ft_swap_int(long *tab);
void	ft_swap(long *tab_a, long *tab_b, char *instruction, int ac);
void	ft_push(long *tab_to, long *tab_from, char *instruction, int ac);
void	ft_big_tab(long *tab_a, long *tab_b, int ac, double divide);
void	ft_which_size(long *tab_a, long *tab_b, int ac);
void	ft_put_on_top_b(long *tab_a, long *tab_b, int size, int index_mini);
void	ft_right_rotate_b(long *tab_a, long *tab_b, int index_closest, int ac);
void	ft_put_b_right(long *tab_a, long *tab_b, int ac);
void	ft_repush_on_a(long *tab_a, long *tab_b, int ac);
void	ft_right_rotate_a(long *tab_a, int ac, long i, long diff);
void	ft_smallest_tab(long *tab_a, long *tab_b, int size);
void	ft_put_on_top_a(long *tab_a, long *tab_b, int size_a, int index_mini);
void	ft_special_case_min_max(long *tab_a, long *tab_b, char *minmax, int ac);
void	ft_before_anything(long *tab_a, long *tab_b, int ac);
void	ft_small_tab(long *tab_a, long *tab_b, int ac);
long	ft_get_index_first(long *tab, int ac, long from, long to);
long	ft_get_index_second(long *tab, int ac, long from, long to);
int		ft_there_is(long *tab, int ac, long from, long to);
int		ft_get_index_max(long *tab, int ac);
long	ft_get_diff_numbers(long *tab, int ac, int divide);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_get_size(long *tab, int ac);
int		ft_get_index_mini(long *tab, int ac);
long	ft_get_max(long *tab, int ac);
long	ft_get_diff(long *tab_a, long *tab_b, char *updown, int ac);

#endif
