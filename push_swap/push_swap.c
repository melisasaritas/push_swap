/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:25 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 17:43:43 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putinstack(t_list **stack_a, int arg)
{
	t_list	*a;

	a = ft_lstnew(arg);
	ft_lstadd_front(stack_a, a);
}

int	*putinarray(t_list *stack_a, int size_a)
{
	t_list	*tmp;
	int		*r;
	int		i;

	tmp = stack_a;
	r = malloc(sizeof(int) * (size_a + 1));
	i = -1;
	while (++i < size_a)
	{
		r[i] = tmp->content;
		tmp = tmp->next;
	}
	r[i] = '\0';
	return (r);
}

void	do_sort(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	*args;
	int	*lis_seq;
	int	lis_len;
	int	size_b;

	lis_len = 0;
	args = putinarray(*stack_a, size_a);
	lis_seq = lis(args, size_a, &lis_len);
	if ((lis_len == 1 && size_a != 1) || (lis_len == 2
			&& find_not_lis(*stack_a, lis_seq, lis_len, size_a) == 1))
	{
		do_sa(stack_a);
		free (args);
		free (lis_seq);
		args = putinarray(*stack_a, size_a);
		lis_seq = lis(args, size_a, &lis_len);
	}
	put_in_b(stack_a, stack_b, lis_seq, lis_len);
	put_in_a(stack_a, stack_b);
	ft_last_sort(stack_a);
	free (args);
	free (lis_seq);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**n;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			n = ft_split(argv[1], ' ');
			argv = ft_strjoin2(argv[0], n);
			argc = word_counter2(argv);
		}
		if (!check_(argc, argv))
		{
			while (--argc > 0)
				putinstack(&stack_a, ft_atoi(argv[argc]));
			size_a = ft_lstsize(stack_a);
			do_sort(&stack_a, &stack_b, size_a);
		}
	}
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
}
