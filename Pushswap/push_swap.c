/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/22 17:36:02 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	enough_args_with_only_numbers_or_spaces(int argc, char **argv)
{
	int	a;
	int	i;

	a = 1;
	if (argc < 2)
		return (ft_printf("No arguments\n"), 1);
	else
	{
		while (a < argc)
		{
			i = 0;
			while (argv[a][i] && (ft_isdigit(argv[a][i]) || argv[a][i] == ' '))
				i++;
			if (argv[a][i] && !ft_isdigit(argv[a][i]))
				return (ft_printf("Digits Error\n"), 1);
			a++;
		}
	}
	return (0);
}

int	not_repeated_args(int argc, char **argv)
{
	int		i;
	int		a;
	int		j;

	a = 1;
	while (a < argc)
	{
		i = 0;
		while (argv[a][i])
		{
			if (argv[a][i] != ' ')
			{
				j = i + 1;
				while (argv[a][j])
				{
					if (argv[a][i] == argv[a][j])
						return (ft_printf("Repeated args\n"), -1);
					j++;
				}
			}
			i++;
		}
		a++;
	}
	return (0);
}

t_stack	**args_to_integer_and_add(int argc, char **argv)
{
	t_stack	**lst_aux;
	char	**res_split;
	int		j;
	int		a;

	lst_aux = NULL;
	a = 1;
	while (a < argc)
	{
		res_split = ft_split(argv[a], ' ');
		j = -1;
		while (res_split[j++])
			ft_stack_add(ft_atol((char *)res_split[j]), lst_aux);
		a++;
	}
	j = -1;
	while (res_split[j++])
		free(res_split[j]);
	free(res_split);
	return (lst_aux);
}

int	main(int argc, char **argv)
{
	t_stack	**lst_a;
	t_stack	**lst_b;
	int		i;
	t_stack	*print_test;

	lst_a = NULL;
	lst_b = NULL;
	i = 0;
	if (enough_args_with_only_numbers_or_spaces(argc, argv) == 0
		&& not_repeated_args(argc, argv) == 0)
		lst_a = args_to_integer_and_add(argc, argv);
	print_test = *lst_a;
	while (print_test != NULL)
	{
		printf("%d\n", print_test->number);
		print_test = print_test->next;
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