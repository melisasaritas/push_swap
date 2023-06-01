/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:02:05 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 16:48:39 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_not_lis(t_list *stack_a, int *lis_seq, int max, int size_a)
{
	int	i;
	int	count;

	count = 0;
	while (stack_a != NULL)
	{
		i = 0;
		while (stack_a->content != lis_seq[i] && i < max)
		{
			if (i == max - 1)
				return (count);
			i++;
		}
		stack_a = stack_a->next;
		count++;
	}
	size_a = -1;
	return (size_a);
}

void	put_in_b(t_list **stack_a, t_list **stack_b, int *lis_seq, int max)
{
	int	i;
	int	size_a;
	int	size_af;

	size_a = ft_lstsize(*stack_a);
	i = find_not_lis(*stack_a, lis_seq, max, size_a);
	size_af = size_a;
	while (i != -1)
	{
		if (i == 2 && size_a == 3)
			do_for_three(stack_a, size_a);
		move_for_a(i, size_a, stack_a);
		if (is_it_sorted(stack_a, size_a))
			break ;
		if (size_af != 3)
			do_pb(stack_a, stack_b);
		i = find_not_lis(*stack_a, lis_seq, max, size_a--);
	}
}

void	do_for_three(t_list **stack_a, int size_a)
{
	do_rra(stack_a);
	if (is_it_sorted(stack_a, size_a))
		return ;
	do_sa(stack_a);
}

void	move_for_a(int i, int size_a, t_list **stack_a)
{
	if (i > 0 && i <= (size_a / 2))
	{
		while (i-- > 0)
		{
			if (is_it_sorted(stack_a, size_a))
				break ;
			do_ra(stack_a);
		}
	}
	else if (i > 0 && i > (size_a / 2))
	{
		i = size_a - i;
		while (i-- > 0)
		{
			if (is_it_sorted(stack_a, size_a))
				break ;
			do_rra(stack_a);
		}
	}
}
