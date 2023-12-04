/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/04 17:57:09 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *lst_a)
{
	int	aux;
	if (!lst_a || !lst_a->next)
		return ;
	if (*(int *)lst_a->content > *(int *)lst_a->next->content)
	{
		aux = *(int *)lst_a->content;
		*(int *)lst_a->content = *(int *)lst_a->next->content;
		*(int *)lst_a->next->content = aux;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_list *lst_b)
{
	int	aux;
	if (!lst_b || !lst_b->next)
		return ;
	if (*(int *)lst_b->content > *(int *)lst_b->next->content)
	{
		aux = *(int *)lst_b->content;
		*(int *)lst_b->content = *(int *)lst_b->next->content;
		*(int *)lst_b->next->content = aux;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_list *lst_a, t_list *lst_b)
{
	ft_sa(lst_a);
	ft_sb(lst_b);
	printf("ss\n");
}

void	ft_pa(t_list *lst_a, t_list *lst_b)
{
	int	aux;
	if (!lst_b)
		return ;
	else
	{
		aux = *(int *)lst_b->content;
//		*(int *)lst_a->content = *(int *)lst_a->next->content;
//		*(int *)lst_a->next->content = aux;
	}
	ft_printf("pa\n");
}

void	ft_pb(t_list *lst_a, t_list *lst_b)
{
	int	aux;
	if (!lst_a)
		return ;
	else
	{
		aux = *(int *)lst_a->content;
//		*(int *)lst_a->content = *(int *)lst_a->next->content;
//		*(int *)lst_a->next->content = aux;
	}
	ft_printf("pb\n");
}

/*
* sa * swap a: Intercambia los dos primeros elementos del stack a.
No hace nada si hay uno o menos elementos.

* sb * swap b: Intercambia los dos primeros elementos del stack b.
No hace nada si hay uno o menos elementos.

* ss * swap a y swap b a la vez.

* pa * push a: Toma el primer elemento del stack b y lo pone el primero
en el stack a. No hace nada si b está vacío.

* pb * push b: Toma el primer elemento del stack a y lo pone el primero
en el stack b. No hace nada si a está vacío.

* ra * rotate a: Desplaza hacia arriba todos los elementos del stack a
una posición, de forma que el primer elemento se convierte en el último.

* rb * rotate b: Desplaza hacia arriba todos los elementos del stack b
una posición, de forma que el primer elemento se convierte en el último.

* rr * ra y rb al mismo tiempo.

* rra * reverse rotate a: Desplaza hacia abajo todos los elementos del stack
a una posición, de forma que el último elemento se convierte en el primero.

* rrb * reverse rotate b: Desplaza hacia abajo todos los elementos del stack b
una posición, de forma que el último elemento se convierte en el primero.

* rrr * rra y rrb al mismo tiempo.*/