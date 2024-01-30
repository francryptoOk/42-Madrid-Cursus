/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:23:11 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/30 19:43:17 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_stack_clear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

int	ft_algorithm(t_stack **lst_a)
{
	if (stack_length(*lst_a) == 3)
		sorting_three_numbers (lst_a);
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