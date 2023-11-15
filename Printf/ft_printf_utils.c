/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/15 18:01:42 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		printcount++;
		i++;
	}
	return (printcount);
}

/*int	ft_puthex(unsigned long long h, int printcount)
{
	char	*hexnbr;

	hexnbr = "0123456789abcdef";
	if (h == 0)
	{
		printcount = ft_putchar_mod('0', printcount);
		return (printcount);
	}
}

int	ft_putptr(void *ptr, int printcount)
{
	printcount = ft_putstr_mod("0x", printcount);
	printcount = ft_putnbr_hex((unsigned long long)ptr, printcount);
	return (printcount);
}*/

int	ft_putnbr_mod(int nb, int printcount)
{
	long	nb_aux;
	char	digit;

	nb_aux = nb;
	if (nb_aux < 0)
	{
		write(1, "-", 1);
		printcount++;
		nb_aux = -nb_aux;
	}
	if (nb_aux < 10)
	{
		digit = nb_aux + 48;
		write(1, &digit, 1);
		printcount++;
	}
	if (nb_aux >= 10)
	{
		ft_putnbr_mod(nb_aux / 10, printcount);
		digit = nb_aux % 10 + 48;
		write(1, &digit, 1);
		printcount++;
	}
	return (printcount);
}
