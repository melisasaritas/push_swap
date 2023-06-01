/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:42 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 16:31:38 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

t_list	*ft_stackbeforelast(t_list *stack);
int		lis_helper_three(int *lis, int size);
void	lis_helper_two(int *dst, int *prev, int *lis, int size);
int		*lis_helper_one(int *prev, int size);
int		*lis_helper(int *lis, int size);
int		*lis(int *dst, int size, int *len);

int		find_not_lis(t_list *stack_a, int *lis_seq, int max, int size_a);
void	put_in_b(t_list **stack_a, t_list **stack_b, int *lis_seq, int max);
void	move_for_a(int i, int size_a, t_list **stack_a);
void	do_for_three(t_list **stack_a, int size_a);

void	put_in_a(t_list **stack_a, t_list **stack_b);
int		put_in_a_helper(t_list **stack_a, t_list **stack_b, int size_b);
int		reverse_or_not(int i, int size_b);
void	put_in_mov_b(int *mov_b, int size_b);
void	put_in_mov_a(int *mov_a, t_list **stack_a,
			t_list **stack_b, int size_b);
int		mov_a_helper(t_list *stack_a, int cont, int size);
int		move_in_a(int a, int b, t_list **stack_a, t_list **stack_b);
int		ft_max_or_min(t_list *stack_a, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);
int		ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size);
int		ft_max_nbr(int a, int b);
int		ft_best_comb(int *mov_a, int *mov_b, int size_b);

int		*ft_intcpy(int *src, size_t n);
void	ft_last_sort(t_list **stack_a);
void	move_lastly(t_list **stack_a, int j);
int		*putinarray(t_list *stack_a, int size_a);

int		word_counter2(char **s);
char	*word_create2(char *s);
char	**ft_strjoin2(char *argv, char **b);
void	ft_lst_delete(t_list **stack);
void	ft_free(char **src);

int		check_(int argc, char **argv);
int		is_it_sorted(t_list **stack_a, int size_a);

void	do_sa(t_list **a);
void	do_sb(t_list **b);
void	do_ss(t_list **a, t_list **b);
void	do_pa(t_list **a, t_list **b);
void	do_pb(t_list **a, t_list **b);
void	do_ra(t_list **a);
void	do_rb(t_list **b);
void	do_rr(t_list **a, t_list **b);
void	do_rra(t_list **a);
void	do_rrb(t_list **b);
void	do_rrr(t_list **a, t_list **b);
#endif
