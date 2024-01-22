/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:27:32 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/22 17:35:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **lst_a)
{
	t_stack	*prev_last;

	prev_last = ft_stack_second_last(*lst_a);
	prev_last->next->next = (*lst_a);
	(*lst_a) = prev_last->next;
	prev_last->next = NULL;
}

void	ft_rrb(t_stack **lst_b)
{
	t_stack	*prev_last;

	prev_last = ft_stack_second_last(*lst_b);
	prev_last->next->next = (*lst_b);
	(*lst_b) = prev_last->next;
	prev_last->next = NULL;
}

void	ft_rrr(t_stack **lst_a, t_stack **lst_b)
{
	ft_rra(lst_a);
	ft_rrb(lst_b);
}

/*
- rra * reverse rotate a: Desplaza hacia abajo todos los elementos del stack
a una posición, de forma que el último elemento se convierte en el primero.

- rrb * reverse rotate b: Desplaza hacia abajo todos los elementos del stack b
una posición, de forma que el último elemento se convierte en el primero.

- rrr * rra y rrb al mismo tiempo.
*/