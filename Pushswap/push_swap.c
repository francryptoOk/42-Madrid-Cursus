/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/30 19:25:45 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int e)
{
	write(2, "Error\n", 6);
	return (e);
}

int	args_sign_numbers_or_spaces(int argc, char **argv)
{
	int	a;
	int	i;

	a = 1;
	while (a < argc)
	{
		i = 0;
		while ((argv[a][i]) && (ft_isdigit(argv[a][i])
			|| (argv[a][i] == ' ')
			|| (argv[a][i] == '-' && ft_isdigit(argv[a][i + 1])
			&& !ft_isdigit(argv[a][i - 1]))
			|| (argv[a][i] == '+' && ft_isdigit(argv[a][i + 1])
			&& !ft_isdigit(argv[a][i - 1]))))
			i++;
		if (argv[a][i] && !ft_isdigit(argv[a][i]))
			return (1);
		a++;
	}
	return (0);
}

t_stack	*args_to_integer_and_add(int argc, char **argv)
{
	t_stack	*lst_aux;
	char	**res_split;
	int		j;
	int		a;

	lst_aux = NULL;
	a = 1;
	while (a < argc)
	{
		res_split = ft_split(argv[a], ' ');
		if (!res_split)
			return (NULL);
		j = 0;
		while (res_split[j])
		{
			if (ft_atoll_int((char *)res_split[j]) > INT_MAX
				|| ft_atoll_int((char *)res_split[j]) < INT_MIN)
				return (NULL);
			ft_stack_add(ft_atoll_int((char *)res_split[j]), &lst_aux);
			j++;
		}
		a++;
	}
	ft_freedom(res_split);
	return (lst_aux);
}

int	not_repeated_numbers(t_stack *begin)
{
	t_stack	*i;
	t_stack	*j;
	int		i_number;

	i = begin;
	while (i != NULL)
	{
		i_number = i->number;
		j = i->next;
		while (j != NULL)
		{
			if (j->number == i_number)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc > 1 && argv[1])
	{
		if (args_sign_numbers_or_spaces(argc, argv) == 0)
		{
			lst_a = args_to_integer_and_add(argc, argv);
			if (lst_a == NULL)
				return (ft_error(1));
		}
		else
			return (ft_error(1));
		if (not_repeated_numbers(lst_a) == 0
			&& numbers_in_order(lst_a) == 0)
			ft_algorithm(&lst_a);
		else
			return (ft_error(1));
		while (lst_a)
		{
			printf("nodo: %d / %p\n", lst_a->number, &lst_a->number);
			lst_a = lst_a->next;
		}
	}
	else
		return (ft_error(1));
	ft_printf("\n\n");
	system("leaks -q push_swap");
	return (0);
}
