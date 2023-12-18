/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/18 17:34:29 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_are_only_numbers_or_spaces(int argc, char **argv)
{
	int	a;
	int	i;

	a = 1;
	i = 0;
	if (argc < 2)
		return (ft_printf("No arguments\n"), -1);
	else
	{
		while (a < argc)
		{
			while (argv[a][i] && (ft_isdigit(argv[a][i]) || argv[a][i] == 32))
				i++;
			if (argv[a][i] && !ft_isdigit(argv[a][i]))
			{
				break ;
				return (ft_printf("Digits Error\n"), -1);
			}
			a++;
		}
	}
	return (0);
}

int	numbers_are_unique(int argc, char **argv)
{
}

int	*args_to_integer(int argc, char **argv)
{
	t_stack	**aux;
	int		i;
	int		a;

	aux = NULL;
	a = 1;
	i = 0;
	while (a < argc)
	{
		while (argv[a][i] != '\0')
		{
			i++;
		}
		aux = ft_split(argv[a], 32);
		a++;
	}
	return (aux);
}

int	main(int argc, char **argv)
{
	t_stack	**lst_a;
	t_stack	**lst_b;
	int		i;
	int		size;
	int		*numbers;

	lst_a = NULL;
	lst_b = NULL;
	i = 0;
	if (args_are_only_numbers_or_spaces(argc, argv) == 0)
	{
		lst_a = args_to_integer(argc, argv);
		while (numbers[i])
		{
			ft_stack_add (numbers[i], lst_a);
			i++;
		}
	}
	return (0);
}

/*
1 2 3 4 5 
"1 2 3 4 5 "
1 2 "3 4" 5
*/

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