/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 17:26:24 by fsantill         ###   ########.fr       */
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
	int		num;

	lst_aux = NULL;
	a = 1;
	while (a < argc)
	{
		res_split = ft_split(argv[a], ' ');
		if (!res_split)
			return (ft_stack_clear(&lst_aux), NULL);
		j = 0;
		while (res_split[j])
		{
			num = ft_atoll_int((char *)res_split[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (ft_freedom(res_split), ft_stack_clear(&lst_aux), NULL);
			ft_stack_add(num, &lst_aux);
			j++;
		}
		a++;
		ft_freedom(res_split);
	}
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
	t_stack	*tmp;

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
		if (not_repeated_numbers(lst_a) == 0 && numbers_in_order(lst_a) == 0)
			ft_algorithm(&lst_a, &lst_b);
		else
			return (ft_error(1));
		tmp = lst_a;
		while (tmp)
		{
			printf("nodo: %d / %p\n", tmp->number, &tmp->number);
			tmp = tmp->next;
		}
	}
	else
		return (ft_error(1));
	ft_stack_clear(&lst_a);
	ft_stack_clear(&lst_b);
	ft_printf("\n\n");
	system("leaks -q push_swap");
	return (0);
}
