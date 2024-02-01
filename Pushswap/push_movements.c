/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:19:38 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 16:42:00 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **lst_a)
{
	t_stack	*aux;

	if (!(*lst_a) || !(*lst_a)->next)
		return ;
	aux = (*lst_a);
	(*lst_a) = aux->next;
	aux->next = (*lst_a)->next;
	(*lst_a)->next = aux;
}

void	ft_sb(t_stack **lst_b)
{
	t_stack	*aux;

	if (!(*lst_b) || !(*lst_b)->next)
		return ;
	aux = (*lst_b);
	(*lst_b) = aux->next;
	aux->next = (*lst_b)->next;
	(*lst_b)->next = aux;
}

void	ft_ss(t_stack **lst_a, t_stack **lst_b)
{
	ft_sa(lst_a);
	ft_sb(lst_b);
}

void	ft_pa(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*aux;

	if (!(*lst_b))
		return ;
	aux = (*lst_b)->next;
	(*lst_b)->next = (*lst_a);
	(*lst_a) = (*lst_b);
	(*lst_b) = aux;
}

void	ft_pb(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*aux;

	if (!lst_a)
		return ;
	aux = (*lst_a)->next;
	(*lst_a)->next = (*lst_b);
	(*lst_b) = (*lst_a);
	(*lst_a) = aux;
}

/*
- sa * swap a: Intercambia los dos primeros elementos del stack a.
No hace nada si hay uno o menos elementos.

- sb * swap b: Intercambia los dos primeros elementos del stack b.
No hace nada si hay uno o menos elementos.

- ss * swap a y swap b a la vez.

- pa * push a: Toma el primer elemento del stack b y lo pone el primero
en el stack a. No hace nada si b está vacío.

- pb * push b: Toma el primer elemento del stack a y lo pone el primero
en el stack b. No hace nada si a está vacío.
*/