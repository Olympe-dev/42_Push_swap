/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:45:36 by opacaud           #+#    #+#             */
/*   Updated: 2021/06/28 09:10:20 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

int		ft_analysis(char **tab_instr);
int		ft_pre_analysis(long *tab_a, long *tab_b, \
char *instr, char **tab_instr);
void	ft_apply_r(long *tab_a, long *tab_b, char *instr, int ac);
void	ft_apply_sp(long *tab_a, long *tab_b, char *instr, int ac);
void	ft_apply(long *tab_a, long *tab_b, char **tab_ins, int ac);
int		ft_check(int ac, char **av);
int		ft_check_char(char **av);
int		ft_check_int(long *tab, int ac);
int		ft_check_int_first(long *tab_a, int ac);
int		ft_check_double(long *tab, int ac);
long	ft_atoi(char *s);
long	*ft_fill_arg(char **av, int ac);
long	*ft_fill_neutral(int ac);
void	ft_sentence(long *tab_a, long *tab_b, int ac);
void	ft_finally(long *tab_a, long *tab_b, char **tab_instr, int ac);
void	ft_free(long *tab_a, long *tab_b, char *instr, char **tab_instr);
void	ft_rotate_tab(long *tab, int ac);
void	ft_rotate(long *tab_a, long *tab_b, char *instruction, int ac);
void	ft_rrotate_tab(long *tab, int ac);
void	ft_rrotate(long *tab_a, long *tab_b, char *instruction, int ac);
void	ft_swap_int(long *tab);
void	ft_swap(long *tab_a, long *tab_b, char *instruction, int ac);
void	ft_push(long *tab_to, long *tab_from, int ac);
char	*ft_fill_str_instr(char *instr, char *tmp);
int		is_bsn(char c);
int		ft_count_lines(char *str);
int		ft_str_s(char *str, int j);
char	**ft_split(char *str);
char	*ft_strjoin(char *ins, char *tmp);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_get_size(long *tab, int ac);
int		ft_is_sorted(long *tab, int ac);
int		ft_is_empty(long *tab, int ac);
int		ft_strlen(char *s);

#endif
