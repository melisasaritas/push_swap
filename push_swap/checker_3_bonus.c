/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:29:09 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 19:47:22 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			if ((argv[argc][0] == '-' && ft_atoi(argv[argc]) != 0))
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
