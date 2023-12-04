/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/04 12:44:25 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_mod(char c, int printcount)
{
	write(1, &c, 1);
	printcount++;
	return (printcount);
}

int	ft_putstr_mod(char *str, int printcount)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		printcount++;
		i++;
	}
	return (printcount);
}

int	ft_checking_the_format(char *str, int i, \
va_list args, int printcount)
{
	if (str[i] == '%')
		printcount = ft_putchar_mod('%', printcount);
	else if (str[i] == 'c')
		printcount = ft_putchar_mod(va_arg(args, int), printcount);
	else if (str[i] == 's')
		printcount = ft_putstr_mod(va_arg(args, char *), printcount);
	else if (str[i] == 'd' || str[i] == 'i')
		printcount = ft_putnbr_mod(va_arg(args, int), printcount);
	else if (str[i] == 'u')
		printcount = ft_putnbr_mod_unsigned(va_arg(args, unsigned int), \
		printcount);
	else if (str[i] == 'p')
		printcount = ft_putptr(va_arg(args, void *), printcount);
	else if (str[i] == 'x')
		printcount = (ft_puthex_low(va_arg(args, unsigned int), printcount));
	else if (str[i] == 'X')
		printcount = (ft_puthex_upp(va_arg(args, unsigned int), printcount));
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
