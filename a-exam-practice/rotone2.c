/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:17:43 by fsantill          #+#    #+#             */
/*   Updated: 2024/05/20 16:48:06 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char c = 'a';

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 90 || argv[1][i] == 122)
				c = argv[1][i] - 25;
			else if ((argv[1][i] >= 65 && argv[1][i] <= 89) ||
				(argv[1][i] >= 97 && argv[1][i] <= 121))
				c = argv[1][i] + 1;
			else
				c = argv[1][i];
			write (1, &c, 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

