/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeos_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:45 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/15 18:01:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	test_format_c(void)
{
	char	aux;

	aux = 'F';
	if (ft_printf("Char: %c", aux) == 7)
	{
		printf ("\n\n>> Test 'c' PrintCount return: 7");
		return (1);
	}
	else
		return (0);
}

int	test_format_s(void)
{
	char	*auxstr;

	auxstr = "Hola!!";
	printf("\n");
	if (ft_printf("String: %s", auxstr) == 14)
	{
		printf ("\n\n>> Test 's' PrintCount return: 14");
		return (1);
	}
	else
		return (0);
}

/*int	test_format_p(void)
{
	void	*auxptr;

	auxptr = NULL;
	printf("\n");
	if (ft_printf("Void Pointer: %p", auxptr) == XX)
	{
		printf ("\n\n>> Test 'p' PrintCount return: XX");
		return (1);
	}
	else
		return (0);
}*/

int	test_format_d_and_i(void)
{
	int	auxnbr;
	int	auxnbr2;

	auxnbr = -123418351;
	auxnbr2 = 4938;
	printf("\n");
	if (ft_printf("Decimal: %d and Integer: %i", auxnbr, auxnbr2) == 26)
	{
		printf ("\n\n>> Test 'd' and 'i' PrintCount return: 26");
		return (1);
	}
	else
		return (0);
}

int	main(void)
{
	if (test_format_c() == 1)
		printf("\n\nFormat 'c' = OKey! :D\n");
	else
		printf("\n\nFormat 'c' = KnOckout! :(\n");
	if (test_format_s() == 1)
		printf("\n\nFormat 's' = OKey! :D\n");
	else
		printf("\n\nFormat 's' = KnOckout! :(\n");
/*	if (test_format_p() == 1)
		printf("\n\nFormat 'p' = OKey! :D\n");
	else
		printf("\n\nFormat 'p' = KnOckout! :(\n");*/
	if (test_format_d_and_i() == 1)
		printf("\n\nFormat 'd' and 'i' = OKey! :D\n");
	else
		printf("\n\nFormat 'd' and 'i' = KnOckout! :(\n");
	return (0);
}
