/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:58:35 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/29 12:14:28 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux = 0;

	aux = *a;
//	printf("aux: %i\n", aux);
	*a = *b;
	*b = aux;
}

/*
int	main(void)
{
	int	a = 1;
	int	b = 2;
	printf("a: %i\nb: %i\n\n", a, b);
	ft_swap(&a, &b);
	printf("a: %i\nb: %i\n", a, b);
	return (0);
}*/
