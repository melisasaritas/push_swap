/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:56:50 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 15:21:31 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	do_sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
