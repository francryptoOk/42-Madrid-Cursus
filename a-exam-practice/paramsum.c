/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:03:31 by fsantill          #+#    #+#             */
/*   Updated: 2024/05/20 18:21:20 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num = (num % 10) + '0';
		write (1, &num, 1);
	}
	else
	{
		num = num + '0';
		write (1, &num, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argv && argc <= 1)
		write (1, "0\n", 2);
	else
	{
		ft_putnbr (argc - 1);
		write (1, "\n", 1);
	}
	return (0);
}

