/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeos_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:45 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/16 17:43:38 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RESET_COLOR "\x1b[0m"
#define ORANGE_COLOR "\x1b[38;5;208m"
#define GREEN_COLOR "\x1b[32m"
#define RED_COLOR "\x1b[31m"

int	test_format_c(void)
{
	char	aux;

	aux = 'F';
	if (ft_printf("Char: %c ", aux) == printf("Char: %c ", aux))
		return (1);
	else
		return (0);
}

int	test_format_s(void)
{
	char	*auxstr;

	auxstr = "Hola!!";
	printf("\n");
	if (ft_printf("String: %s ", auxstr) == printf("String: %s ", auxstr))
		return (1);
	else
		return (0);
}

int	test_format_p(void)
{
	void	*auxptr;

	auxptr = "1545364";
	printf("\n");
	if (ft_printf("Void Pointer: %p ", auxptr) \
	== printf("Void Pointer: %p ", auxptr))
		return (1);
	else
		return (0);
}

int	test_format_d_and_i(void)
{
	int	auxnbr;
	int	auxnbr2;

	auxnbr = -123418351;
	auxnbr2 = 4938;
	printf("\n");
	if (ft_printf("Decimal: %d and Integer: %i ", auxnbr, auxnbr2) \
	== printf("Decimal: %d and Integer: %i ", auxnbr, auxnbr2))
		return (1);
	else
		return (0);
}

int	test_format_u(void)
{
	int	auxnbrneg;
	int	auxnbrpos;

	auxnbrneg = -12;
	auxnbrpos = 12;
	printf("\n");
	if (ft_printf("Neg!!: %u and Pos: %u ", auxnbrneg, auxnbrpos) \
	== printf("Neg!!: %u and Pos: %u ", auxnbrneg, auxnbrpos))
		return (1);
	else
		return (0);
}

int	test_format_x_and_X(void)
{
	int	auxhex;
	int	auxhex2;

	auxhex = 0x1a;
	auxhex2 = 0xf21;
	printf("\n");
	if (ft_printf("Hex: %x and Hex2: %X ", auxhex, auxhex2) \
	== printf("Hex: %x and Hex2: %X ", auxhex, auxhex2))
		return (1);
	else
		return (0);
}

int	test_format_percentage(void)
{
	printf("\n");
	if (ft_printf("Percentage: %% ") == printf("Percentage: %% "))
		return (1);
	else
		return (0);
}

int	main(void)
{
	printf(ORANGE_COLOR "\n╔╗ FRANCRYPTO® 💡🔗💻\n╠╗  Tester by fsantill\n═╝\n \
	● Comparing my FT_PRINTF vs PRINTF ●\n" RESET_COLOR "\n");
	if (test_format_c() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'c' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'c' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_s() == 1)
		printf(GREEN_COLOR "\n\n<< Format 's' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 's' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_p() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'p' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'p' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_d_and_i() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'd' and 'i' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'd' and 'i' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_u() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'u' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'u' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_u() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'u' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'u' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_x_and_X() == 1)
		printf(GREEN_COLOR "\n\n<< Format 'x' and 'X' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format 'x' and 'X' = KnOckout! ❌ >>\n" RESET_COLOR);
	if (test_format_percentage() == 1)
		printf(GREEN_COLOR "\n\n<< Format '%%' = OKey! ✅ >>\n" RESET_COLOR);
	else
		printf(RED_COLOR "\n\n<< Format '%%' = KnOckout! ❌ >>\n" RESET_COLOR);
	printf(ORANGE_COLOR "\n\t● 👋 Tester Finished 👋 ●\n" RESET_COLOR "\n");
	return (0);
}
