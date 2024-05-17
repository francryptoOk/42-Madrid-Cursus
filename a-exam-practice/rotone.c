/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:24:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/20 14:17:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	j;

	if (argc != 2)
		return (write (1, "\n", 1));
	j = 0;
	while (argv[1][j] != '\0')
	{
		if (argv[1][j] == 'z' || argv[1][j] == 'Z')
			argv[1][j] = argv[1][j] - 25;
		else if ((argv[1][j] >= 'a' && argv[1][j] < 'z') || (argv[1][j] >= 'A' && argv[1][j] < 'Z'))
			argv[1][j] = argv[1][j] + 1;
		write(1, &argv[1][j], 1);
		j++;
	}
	write (1, "\n", 1);
	return (0);
}
