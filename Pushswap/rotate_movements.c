/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:25:56 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/13 12:41:23 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **lst_a)
{
	t_stack	*last;

	last = ft_stack_last(*lst_a);
	last->next = (*lst_a);
	(*lst_a) = (*lst_a)->next;
	last->next->next = NULL;
}

void	ft_rb(t_stack **lst_b)
{
	t_stack	*last;

	last = ft_stack_last(*lst_b);
	last->next = (*lst_b);
	(*lst_b) = (*lst_b)->next;
	last->next->next = NULL;
}

void	ft_rr(t_stack **lst_a, t_stack **lst_b)
{
	ft_ra(lst_a);
	ft_rb(lst_b);
}

/*
- ra * rotate a: Desplaza hacia arriba todos los elementos del stack a
una posición, de forma que el primer elemento se convierte en el último.

- rb * rotate b: Desplaza hacia arriba todos los elementos del stack b
una posición, de forma que el primer elemento se convierte en el último.

- rr * ra y rb al mismo tiempo.
*/