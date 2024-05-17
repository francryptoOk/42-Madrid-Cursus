/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:28:46 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/28 17:04:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc != 2)
		write (1, "\n", 1);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 65 && argv[1][i] <= 90)
		{
			argv[1][i] = 90 - argv[1][i] + 65;
			write (1, &argv[1][i], 1);
		}
		else if(argv[1][i] >= 97 && argv[1][i] <= 122)
		{
			argv[1][i] = 122 - argv[1][i] + 97;
			write (1, &argv[1][i], 1);
		}
		else
			write (1, &argv[1][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
/*
	90 'Z'
	- 70 'F' (need to be 'U')
	subtotal = 20
	+ 65 'A'
	result = 85 'U'

	abcdefghijklm
	zyxwvutsrqpon
*/
