/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:23:11 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/24 15:53:23 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algorithm(t_stack *lst_a)
{
	if (lst_a && lst_a->next && lst_a->next->next && !(lst_a->next->next->next))
		sorting_three_numbers (&lst_a);
	return (0);
}

int	sorting_three_numbers(t_stack **lst_a)
{
	t_stack *two;
	t_stack *third;

	two = ft_stack_second_last(&lst_a);
	third = ft_stack_last(&lst_a);

	while ((*lst_a) && (*lst_a)->next)
	{
		if (third->number > (*lst_a)->number
			&& (*lst_a)->number < two->number
			&& two->number > third->number) // ...>0<2>1
			{
				ft_sa(&lst_a);
				ft_ra(&lst_a);
				return (printf("sa\nra\n"), 0);
			}
		else if (third->number > (*lst_a)->number
			&& (*lst_a)->number < two->number
			&& two->number < third->number) // ...>1<0<2
			{
				ft_sa(&lst_a);
				ft_rra(&lst_a);
				return (printf("sa\nrra\n"), 0);
			}
		else if (third->number < (*lst_a)->number
			&& (*lst_a)->number < two->number
			&& two->number > third->number) // ...<1<2>0
			return (ft_rra(&lst_a), ft_printf("rra\n"), 0);
		else if (third->number < (*lst_a)->number
			&& (*lst_a)->number > two->number
			&& two->number < third->number) // ...<2>0<1
			return (ft_ra(&lst_a), ft_printf("ra\n"), 0);
		else if (third->number < (*lst_a)->number
			&& (*lst_a)->number > two->number
			&& two->number > third->number) // ...<2>1>0
			return (ft_sa(&lst_a), ft_printf("sa\n"), 0);
	}
	return (1);
}
