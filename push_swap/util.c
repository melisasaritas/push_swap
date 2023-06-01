/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:43:34 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/24 16:28:44 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_or_not(int i, int size_b)
{
	if (i > (size_b / 2))
		return (i - size_b);
	return (i);
}

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

int	*ft_intcpy(int *src, size_t n)
{
	size_t	i;
	int		*dst;

	dst = malloc(sizeof(int) * n);
	if (!dst && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}

void	ft_last_sort(t_list **stack_a)
{
	int	i;
	int	j;
	int	c;
	int	*args;
	int	size_a;

	j = -1;
	size_a = ft_lstsize(*stack_a);
	args = putinarray(*stack_a, size_a);
	c = 0;
	while (++j < size_a)
	{
		if (args[c] > args[j])
			c = j;
	}
	i = reverse_or_not(c, size_a);
	move_lastly(stack_a, i);
	free (args);
}

void	move_lastly(t_list **stack_a, int j)
{
	if (j < 0)
	{
		j *= -1;
		while (j-- > 0)
			do_rra(stack_a);
	}
	else if (j > 0)
	{
		while (j-- > 0)
			do_ra(stack_a);
	}
}
