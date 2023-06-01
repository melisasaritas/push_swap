/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:25:48 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 18:00:37 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkduplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkisnumber(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (--argc != 0)
	{
		i = -1;
		while (argv[argc][++i])
		{
			if ((argv[argc][i] > '9' || argv[argc][i] < '0')
				|| (ft_strlen(argv[argc]) != 1 && ft_atoi(argv[argc]) == -1))
				j = 1;
			if (argv[argc][0] == '-')
				j = 0;
		}
	}
	return (j);
}

int	check_(int argc, char **argv)
{
	if (checkisnumber(argc, argv))
		ft_printf("Error\n");
	else if (checkduplicate(argc, argv))
		ft_printf("Error\n");
	if ((checkisnumber(argc, argv)) || (checkduplicate(argc, argv)))
		return (1);
	return (0);
}

int	is_it_sorted(t_list **stack_a, int size_a)
{
	int	i;
	int	j;
	int	*args;

	i = -1;
	args = putinarray(*stack_a, size_a);
	while (++i < size_a)
	{
		j = i;
		while (++j < size_a)
		{
			if (args[i] > args[j])
			{
				free (args);
				return (0);
			}
		}
	}
	free (args);
	return (1);
}
