/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeos_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:45 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/14 17:33:41 by fsantill         ###   ########.fr       */
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
	return (0);
}
