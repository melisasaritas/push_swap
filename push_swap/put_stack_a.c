/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:53:25 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 16:55:44 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_mov_b(int *mov_b, int size_b)
{
	int	i;

	i = -1;
	while (++i < size_b)
		mov_b[i] = reverse_or_not(i, size_b);
}

void	put_in_mov_a(int *mov_a, t_list **stack_a, t_list **stack_b, int size_b)
{
	t_list	*tmp;
	int		size_a;
	int		i;

	tmp = *stack_b;
	size_a = ft_lstsize(*stack_a);
	i = -1;
	while (++i < size_b && tmp != NULL)
	{
		mov_a[i] = mov_a_helper(*stack_a, tmp->content, size_a);
		tmp = tmp->next;
	}
	ft_lst_delete(&tmp);
}

int	mov_a_helper(t_list *stack_a, int cont, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return (reverse_or_not(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (cont < stack_a->content && cont > tmp->content)
		return (0);
	i = 1;
	while (!(cont > stack_a->content && cont < (stack_a->next)->content))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (reverse_or_not(i, size));
}

int	put_in_a_helper(t_list **stack_a, t_list **stack_b, int size_b)
{
	int	*mov_a;
	int	*mov_b;
	int	i;

	mov_a = malloc(sizeof(int) * (size_b));
	mov_b = malloc(sizeof(int) * (size_b));
	put_in_mov_b(mov_b, size_b);
	put_in_mov_a(mov_a, stack_a, stack_b, size_b);
	i = ft_best_comb(ft_intcpy(mov_a, size_b),
			ft_intcpy(mov_b, size_b), size_b);
	i = move_in_a(mov_a[i], mov_b[i], stack_a, stack_b);
	free (mov_a);
	free (mov_b);
	return (i);
}

void	put_in_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		i = put_in_a_helper(stack_a, stack_b, size_b);
		if (i < 0)
			while (i++ < 0)
				do_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				do_rb(stack_b);
		do_pa(stack_a, stack_b);
		size_a++;
		size_b--;
	}
}
