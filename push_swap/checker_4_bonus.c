/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_4_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:31:33 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 20:02:31 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_other_instructions(t_list **stack_a,
		t_list **stack_b, char *line, int *i)
{
	if (!ft_strncmp(line, "rr", 2) && ft_strlen(line) == 3)
	{
		rotate (stack_a);
		rotate (stack_b);
	}
	else if (!ft_strncmp(line, "rra", 3) && ft_strlen(line) == 4)
		rev_rotate (stack_a);
	else if (!ft_strncmp(line, "rrb", 3) && ft_strlen(line) == 4)
		rev_rotate (stack_b);
	else if (!ft_strncmp(line, "rrr", 3) && ft_strlen(line) == 4)
	{
		rev_rotate (stack_a);
		rev_rotate (stack_b);
	}
	else
		*i = 1;
}

int	find_and_do_the_instructions(t_list **stack_a,
		t_list **stack_b, char *line, int i)
{
	if (!ft_strncmp(line, "sa", 2) && ft_strlen(line) == 3)
		swap (*stack_a);
	else if (!ft_strncmp(line, "sb", 2) && ft_strlen(line) == 3)
		swap (*stack_b);
	else if (!ft_strncmp(line, "ra", 2) && ft_strlen(line) == 3)
		rotate (stack_a);
	else if (!ft_strncmp(line, "rb", 2) && ft_strlen(line) == 3)
		rotate (stack_b);
	else if (!ft_strncmp(line, "pa", 2) && ft_strlen(line) == 3)
		push (stack_b, stack_a);
	else if (!ft_strncmp(line, "pb", 2) && ft_strlen(line) == 3)
		push (stack_a, stack_b);
	else
		do_other_instructions(stack_a, stack_b, line, &i);
	free (line);
	return (i);
}
