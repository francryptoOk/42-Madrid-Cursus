/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:21:11 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/30 15:31:26 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 4)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[2][1] || argv[3][1])
				break ;
			if (argv[1][i] == argv[2][0])
				write (1, &argv[3][0], 1);
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
