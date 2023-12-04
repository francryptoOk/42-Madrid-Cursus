/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/04 12:44:20 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_low(unsigned long long h, int printcount)
{
	char	*hexlow;

	hexlow = "0123456789abcdef";
	if (h < 16)
		printcount = ft_putchar_mod(hexlow[h], printcount);
	else
	{
		printcount = ft_puthex_low(h / 16, printcount);
		printcount = ft_puthex_low(h % 16, printcount);
	}
	return (printcount);
}

int	ft_puthex_upp(unsigned long long h, int printcount)
{
	char	*hexupp;

	hexupp = "0123456789ABCDEF";
	if (h < 16)
		printcount = ft_putchar_mod(hexupp[h], printcount);
	else
	{
		printcount = ft_puthex_upp(h / 16, printcount);
		printcount = ft_puthex_upp(h % 16, printcount);
	}
	return (printcount);
}

int	ft_putptr(void *ptr, int printcount)
{
	printcount = ft_putstr_mod("0x", printcount);
	printcount = ft_puthex_low((unsigned long)ptr, printcount);
	return (printcount);
}

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
	if (nb_aux >= 10)
		printcount = ft_putnbr_mod(nb_aux / 10, printcount);
	digit = nb_aux % 10 + 48;
	write(1, &digit, 1);
	printcount++;
	return (printcount);
}

int	ft_putnbr_mod_unsigned(unsigned int nb, int printcount)
{
	long	nb_aux;
	char	digit;

	nb_aux = nb;
	if (nb_aux >= 10)
		printcount = ft_putnbr_mod(nb_aux / 10, printcount);
	digit = nb_aux % 10 + 48;
	write(1, &digit, 1);
	printcount++;
	return (printcount);
}
