/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/23 15:54:53 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_freedom(char **p)
{
	if (p && *p)
		free (*p);
	*p = NULL;
	return (NULL);
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
			return (ft_printf("Digits Error\n"), 1);
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
		j = 0;
		while (res_split[j])
		{
			if (ft_atol_int((char *)res_split[j]) > INT_MAX
				|| ft_atol_int((char *)res_split[j]) < INT_MIN)
				return (ft_printf("Error not integer\n"), NULL);
			ft_stack_add(ft_atol_int((char *)res_split[j]), &lst_aux);
			j++;
		}
		a++;
	}
	ft_freedom(res_split);
	return (lst_aux);
}

int	empty_or_not_repeated_numbers(t_stack *begin)
{
	t_stack	*i;
	t_stack	*j;
	int		i_number;

	i = begin;
	if (i == NULL)
		return (ft_printf("Empty\n"), 1);
	while (i != NULL)
	{
		i_number = i->number;
		j = i->next;
		while (j != NULL)
		{
			if (j->number == i_number)
				return (ft_printf("Repeated numbers\n"), 1);
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
	if (argc != 1)
	{
		if (args_sign_numbers_or_spaces(argc, argv) == 0)
			lst_a = args_to_integer_and_add(argc, argv);
		else
			return (1);
		if (empty_or_not_repeated_numbers(lst_a) == 0)
			ft_printf("I need to develop the sorting algorithm :( \n\n");
		else
			return (1);
		while (lst_a != NULL)
		{
			printf("Aca: %d\n", lst_a->number);
			lst_a = lst_a->next;
		}
	}
	else
		return (ft_printf("No arguments\n"), 1);
	return (0);
}
