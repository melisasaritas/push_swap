/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:58:59 by msaritas          #+#    #+#             */
/*   Updated: 2022/10/22 16:37:22 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printc(int c);
int	ft_printcapitalx(unsigned int d);
int	ft_printf(const char *str, ...);
int	ft_printi(int d);
int	ft_printp(unsigned long long d);
int	ft_prints(char *s);
int	ft_printu(unsigned int d);
int	ft_printx(unsigned int d);

#endif
