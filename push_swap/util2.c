/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:40:36 by msaritas          #+#    #+#             */
/*   Updated: 2023/02/25 17:41:44 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_counter2(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*word_create2(char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	**ft_strjoin2(char *argv, char **b)
{
	char	**total;
	size_t	w;

	w = -1;
	total = (char **)malloc((word_counter2(b) + 2) * sizeof(char *));
	if (!total || !b || !argv)
		return (NULL);
	total[0] = word_create2(argv);
	while (b[++w])
		total[w + 1] = word_create2(b[w]);
	total[w + 1] = 0;
	ft_free(b);
	return (total);
}

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}

void	ft_free(char **src)
{
	int	i;
	int	j;

	i = -1;
	while (src[++i])
		free (src[i]);
}
