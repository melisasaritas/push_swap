/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:12:35 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 20:03:09 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	if_it_is_ok(t_list **stack_a, t_list **stack_b)
{
	int	*args;
	int	size_a;
	int	size_b;
	int	i;
	int	j;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	args = putinarray(*stack_a, size_a);
	i = -1;
	while (++i < size_a)
	{
		j = i;
		while (++j < size_a)
		{
			if (args[i] > args[j] || size_b)
			{
				ft_printf("KO\n");
				free (args);
				return ;
			}
		}
	}
	free (args);
	ft_printf("OK\n");
}

void	if_argc_two(int *argc, char ***argv)
{
	char	**n;

	if (!ft_strlen((*argv)[1]))
		return ;
	n = ft_split((*argv)[1], ' ');
	*argv = ft_strjoin2((*argv)[0], n);
	*argc = word_counter2(*argv);
}

void	take_the_lines(t_list **stack_a, t_list **stack_b, int *i)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free (line);
			*i = 1;
			break ;
		}
		find_and_do_the_instructions(stack_a, stack_b, line, *i);
	}
}

void	if_not_instruction(t_list **stack_a, t_list **stack_b)
{
	ft_printf("Error\n");
	ft_lst_delete(stack_a);
	ft_lst_delete(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 1)
	{
		if (!ft_strlen(argv[1]))
		{
			ft_printf("Error\n");
			return (0);
		}
		else if (argc == 2)
			if_argc_two(&argc, &argv);
		else if (!check_(argc, argv))
		{
			if (!ft_strlen(argv[1]))
				i = 1;
			while (--argc > 0)
				putinstack(&stack_a, ft_atoi(argv[argc]));
			take_the_lines(&stack_a, &stack_b, &i);
			if (i)
			{
				if_not_instruction(&stack_a, &stack_b);
				return (0);
			}
			if_it_is_ok(&stack_a, &stack_b);
		}
	}
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
}
