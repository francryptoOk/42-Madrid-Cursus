/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:16:27 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/29 12:44:20 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	is_power_of_2(unsigned int n)
{
//	printf("n: %u\n", n);
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else if (n % 2 == 0)
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	int	n1 = 1;
	int	n2 = 2;
	int	n3 = 4;
	int	n4 = 8;
	int	n5 = 16;
	int	n6 = 32;
	int	n7 = 64;
	int	r1 = is_power_of_2(n1);
	int	r2 = is_power_of_2(n2);
	int	r3 = is_power_of_2(n3);
	int	r4 = is_power_of_2(n4);
	int	r5 = is_power_of_2(n5);
	int	r6 = is_power_of_2(n6);
	int r7 = is_power_of_2(n7);
	int	r8 = is_power_of_2(argv[1][0] - '0');
	printf("Resultados: \n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n", r1, r2, r3, r4, r5, r6, r7, r8);
}

// 1 2 4 8 16 32 64 etc*/
