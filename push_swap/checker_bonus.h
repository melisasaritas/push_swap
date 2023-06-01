/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:23:14 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 19:09:02 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

void	swap(t_list *stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
t_list	*ft_stackbeforelast(t_list *stack);
void	rev_rotate(t_list **stack);

int		word_counter2(char **s);
char	*word_create2(char *s);
char	**ft_strjoin2(char *argv, char **b);
void	ft_lst_delete(t_list **stack);
void	ft_free(char **src);

void	putinstack(t_list **stack_a, int arg);
int		*putinarray(t_list *stack_a, int size_a);
int		checkduplicate(int argc, char **argv);
int		checkisnumber(int argc, char **argv);
int		check_(int argc, char **argv);

void	do_other_instructions(t_list **stack_a,
			t_list **stack_b, char *line, int *i);
int		find_and_do_the_instructions(t_list **stack_a,
			t_list **stack_b, char *line, int i);

#endif
