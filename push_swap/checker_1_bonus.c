/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:21:15 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 20:02:14 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL || *dest == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	if (!*stack)
		return ;
	tail = ft_lstlast(*stack);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

t_list	*ft_stackbeforelast(t_list *stack)
{
	while (stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rev_rotate(t_list **stack)
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
