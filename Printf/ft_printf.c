/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/14 17:40:43 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c, int printcount)
{
	write(1, &c, 1);
	printcount++;
	return (printcount);
}

int	ft_putstr(char *str, int printcount)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		printcount++;
		i++;
	}
	return (printcount);
}

int	ft_checking_the_format(char *str, int i, va_list args, int printcount)
{
	if (str[i] == 'c')
		printcount = ft_putchar(va_arg(args, int), printcount);
	else if (str[i] == 's')
		printcount = ft_putstr(va_arg(args, char *), printcount);
	else if (str[i] == 'p')
		printf("TO CONTINUE with 'p' HEREEEEEE... JEJE");
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
			printcount = ft_putchar(str[i], printcount);
		i++;
	}
	va_end(args);
	return (printcount);
}
