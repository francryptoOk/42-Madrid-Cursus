/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/04 15:21:05 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_are_numbers(int argc, char **argv)
{
	int	a;
	int i;

	a = 1;
	i = 0;
	if (argc < 2)
		return (ft_printf("No arguments\n"), -1);
	else
	{
		while(a < argc)
		{
			while(argv[a][i] && ((ft_isdigit(argv[a][i])) || \
			(argv[a][i] == 32 || (argv[a][i] > 9 && argv[a][i] < 15))))
				i++;
			if(argv[a][i] && !ft_isdigit(argv[a][i]))
			{
				ft_printf("Digits Error\n");
				break ;
			}
			a++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	args_are_numbers(argc, argv);
	return (0);
}

/*
int		tree_states[][4] = {
//	\s, -, D, Error
	{0, 1, 3, 2}, // Empty
	{2, 2, 3, 2}, // Negative -
	{2, 2, 2, 2}, // Invalid
	{4, 2, 3, 2}, // Digit found
	{4, 1, 3, 2}, // Space after digit
};

void	tree_alphabet(t_automata *a)
{
	a->alphabet = ft_(NULL, " ");
	a->alphabet = ft_(a->alphabet, "-");
	a->alphabet = ft_(a->alphabet, "0123456789");
}*/