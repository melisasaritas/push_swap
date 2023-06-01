/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:22:33 by msaritas          #+#    #+#             */
/*   Updated: 2022/10/22 16:42:05 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_number(unsigned int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count = 2;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printu(unsigned int d)
{
	int	a;

	if (d < 10 && d >= 0)
		ft_printc('0' + d % 10);
	else
	{
		ft_printu(d / 10);
		ft_printc('0' + d % 10);
	}
	a = digit_number(d);
	return (a);
}
