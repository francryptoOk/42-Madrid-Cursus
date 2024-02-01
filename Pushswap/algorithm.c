/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:23:11 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 17:55:35 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algorithm(t_stack **lst_a, t_stack **lst_b)
{
	if (stack_length(*lst_a) == 2)
		return (ft_sa(lst_a), ft_printf("sa\n"), 0);
	else if (stack_length(*lst_a) == 3)
		sorting_three_numbers(lst_a);
	else if (stack_length(*lst_a) == 4)
		sorting_four_numbers(lst_a, lst_b);
	else if (stack_length(*lst_a) == 5)
		sorting_five_numbers(lst_a, lst_b);
	return (0);
}

int	sorting_five_numbers(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	**fifth;

	fifth = NULL;
	(*fifth)->number = ft_min_node((*lst_a));
	ft_pb(fifth, lst_b);
	ft_printf("pb\n");
	sorting_four_numbers(&(*lst_a), &(*lst_b));
	ft_pa(lst_a, lst_b);
	ft_printf("pa\n");
	return (0);
}

int	sorting_four_numbers(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	**fourth;

	fourth = NULL;
	(*fourth)->number = ft_min_node((*lst_a));
	ft_pb(fourth, lst_b);
	ft_printf("pb\n");
	sorting_three_numbers(&(*lst_a));
	ft_pa(lst_a, lst_b);
	ft_printf("pa\n");
	return (0);
}

int	sorting_three_numbers(t_stack **lst_a)
{
	int	first;
	int	second;
	int	third;

	first = (*lst_a)->number;
	second = ft_stack_second_last((*lst_a))->number;
	third = ft_stack_last((*lst_a))->number;
	ft_printf("Stack inicial:\n\n1er nodo> %p / %i\n", &first, first);
	ft_printf("2do nodo> %p / %i\n", &second, second);
	ft_printf("3er nodo> %p / %i\n", &third, third);
	if (ft_min_node((*lst_a)) == third && ft_max_node((*lst_a)) == second)
		return (ft_rra(lst_a), ft_printf("rra\n"), 0);
	else if (ft_min_node((*lst_a)) == second && ft_max_node((*lst_a)) == first)
		return (ft_ra(lst_a), ft_printf("ra\n"), 0);
	else if (ft_min_node((*lst_a)) == second && ft_max_node((*lst_a)) == third)
		return (ft_sa(lst_a), printf("sa\n"), 0);
	else if (ft_min_node((*lst_a)) == third && ft_max_node((*lst_a)) == first)
		return (ft_sa(lst_a), ft_rra(lst_a), ft_printf("sa\nrra\n"), 0);
	else if (ft_min_node((*lst_a)) == first && ft_max_node((*lst_a)) == second)
		return (ft_sa(lst_a), ft_ra(lst_a), printf("sa\nra\n"), 0);
	return (1);
}

// ...<1<2>0 OKEY
// ...<2>0<1 OKEY
// ...>1<0<2 OKEY
// ...<2>1>0 OKEY
// ...>0<2>1 OKEY

// algoritmo turco> dividir a la mitad o buscar la media para optimizarlo