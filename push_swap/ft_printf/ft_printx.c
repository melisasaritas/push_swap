/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:51:43 by msaritas          #+#    #+#             */
/*   Updated: 2022/10/22 16:42:57 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_number(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_printx(unsigned int d)
{
	int	a;

	if (d < 16 && d >= 0)
		ft_printc("0123456789abcdef"[d]);
	else
	{
		ft_printx(d / 16);
		ft_printx(d % 16);
	}
	a = digit_number(d);
	return (a);
}
