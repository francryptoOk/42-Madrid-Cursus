/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:23:11 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/29 15:34:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algorithm(t_stack **lst_a)
{
	if (stack_length(*lst_a) == 3)
		sorting_three_numbers (lst_a);
	return (0);
}

int	sorting_three_numbers(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = (*lst_a);
	second = ft_stack_second_last((*lst_a));
	third = ft_stack_last((*lst_a));
	if (ft_min_node(third) && ft_max_node(second))
		return (ft_rra(lst_a), ft_printf("rra\n"), 0);
	else if (ft_min_node(second) && ft_max_node (first)) // falta el ultimo
		return (ft_ra(lst_a), ft_printf("ra\n"), 0);
	else if (ft_min_node(third) && ft_max_node (first))
		return (ft_sa(lst_a), ft_printf("sa\n"), 0);
	else if (ft_min_node(first) && ft_max_node(second)) // falta el ultimo
		return (ft_sa(lst_a), ft_ra(lst_a), printf("sa\nra\n"), 0);
	else if (ft_min_node(second) && ft_max_node (third)) // falta el ultimo
		return (ft_sa(lst_a), ft_rra(lst_a), printf("sa\nrra\n"), 0);
	return (1);
}

// ...<1<2>0
// ...<2>0<1
// ...<2>1>0
// ...>0<2>1
// ...>1<0<2