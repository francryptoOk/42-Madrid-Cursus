/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/15 18:01:43 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_checking_the_format(char *str, int i, \
va_list args, int printcount)
{
	if (str[i] == 'c')
		printcount = ft_putchar_mod(va_arg(args, int), printcount);
	else if (str[i] == 's')
		printcount = ft_putstr_mod(va_arg(args, char *), printcount);
//	else if (str[i] == 'p')
//		ft_putptr / ft_puthex;
	else if (str[i] == 'd' || str[i] == 'i')
		printcount = ft_putnbr_mod(va_arg(args, int), printcount);
	else if (str[i] == 'u')
		printcount = 0;
	else if (str[i] == 'x')
		printcount = 0;
	else if (str[i] == 'X')
		printcount = 0;
	else if (str[i] == '%')
		printcount = ft_putchar_mod('%', printcount);
	return (printcount);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		printcount;
	va_list	args;

	va_start(args, str);
	i = 0;
	printcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			printcount = ft_checking_the_format((char *)str, i, \
			args, printcount);
		}
		else
			printcount = ft_putchar_mod(str[i], printcount);
		i++;
	}
	va_end(args);
	return (printcount);
}
