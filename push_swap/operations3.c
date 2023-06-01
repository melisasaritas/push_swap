/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:03:24 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 17:10:05 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tail = ft_lstlast(*stack);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
