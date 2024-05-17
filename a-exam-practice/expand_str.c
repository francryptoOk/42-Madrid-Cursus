/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:43:20 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/27 12:38:24 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] == ' ')
				i++;
			while (argv[1][i] != ' ')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			while (argv[1][i] == ' ')
				i++;
			if (argv[1][i] == '\0')
				break ;
			write(1, "   ", 3);
		}
		write(1, "\n", 1);
	}
	return (0);
}
