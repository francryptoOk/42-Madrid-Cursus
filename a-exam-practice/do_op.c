/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:37:13 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/29 16:28:35 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%i", (atoi(argv[1]) + atoi(argv[3])));
		else if (argv[2][0] == '-')
			printf("%i", (atoi(argv[1]) - atoi(argv[3])));
		else if (argv[2][0] == '*')
			printf("%i", (atoi(argv[1]) * atoi(argv[3])));
		else if (argv[2][0] == '/')
			printf("%i", (atoi(argv[1]) / atoi(argv[3])));
		else if (argv[2][0] == '%')
			printf("%i", (atoi(argv[1]) % atoi(argv[3])));
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}
