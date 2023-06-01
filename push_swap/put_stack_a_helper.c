/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_a_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:55:40 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 17:02:41 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_max_or_min(int cont, int *max_n_min, int size)
{
	if (cont > max_n_min[0])
	{
		free (max_n_min);
		return (max_n_min[2]);
	}
	if (cont < max_n_min[1])
	{
		free (max_n_min);
		return (max_n_min[3]);
	}
	free (max_n_min);
	return (size + 1);
}

int	ft_max_or_min(t_list *stack_a, int cont, int size)
{
	int	*max_n_min;
	int	i;

	max_n_min = malloc(sizeof(int) * 4);
	max_n_min[0] = stack_a->content;
	max_n_min[1] = stack_a->content;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	i = 1;
	while (stack_a != NULL)
	{
		if (stack_a->content >= max_n_min[0])
		{
			max_n_min[0] = stack_a->content;
			max_n_min[2] = i;
		}
		if (stack_a->content < max_n_min[1])
		{
			max_n_min[1] = stack_a->content;
			max_n_min[3] = i - 1;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
	}
	free (arr_a);
	free (arr_b);
	free (tmp);
	return (pos);
}

int	ft_best_comb(int *mov_a, int *mov_b, int size_b)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *) malloc (sizeof(int) * size_b);
	while (++i < size_b)
	{
		if ((mov_a[i] > 0 && mov_b[i] > 0)
			|| (mov_a[i] < 0 && mov_b[i] < 0))
			tmp[i] = ft_max_nbr(mov_a[i], mov_b[i]);
		else
		{
			if (mov_a[i] < 0)
				mov_a[i] *= -1;
			if (mov_b[i] < 0)
				mov_b[i] *= -1;
			tmp[i] = mov_a[i] + mov_b[i];
		}
	}
	return (ft_best_comb_helper(mov_a, mov_b, tmp, size_b));
}

int	move_in_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a < 0 && b < 0)
	{
		do_rrr(stack_a, stack_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		do_rr(stack_a, stack_b);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			do_rra(stack_a);
	else if (a > 0)
		while (a-- > 0)
			do_ra(stack_a);
	return (b);
}
