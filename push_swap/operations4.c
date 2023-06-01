/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:17:53 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 14:42:10 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_stackbeforelast(t_list *stack)
{
	while (stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = ft_lstlast(*stack);
	before_tail = ft_stackbeforelast(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
