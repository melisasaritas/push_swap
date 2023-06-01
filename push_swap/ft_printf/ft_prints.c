/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:37:00 by msaritas          #+#    #+#             */
/*   Updated: 2022/10/22 16:41:00 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(char *s)
{
	int	a;
	int	l;

	a = 0;
	l = 0;
	if (s == NULL)
	{
		ft_prints("(null)");
		return (6);
	}
	while (s[a])
	{
		write(1, &s[a++], 1);
		l++;
	}
	return (l);
}
