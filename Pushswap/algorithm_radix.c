/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:09:35 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/12 16:11:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_node_id_assignment(t_stack **lst)
{
	int		position;
	int		lst_size;
	t_stack	*temp_first;
	t_stack	*temp_second;

	temp_first = (*lst);
	lst_size = ft_stacksize((*lst));
	while (lst_size > 0)
	{
		position = 0;
		temp_second = (*lst);
		while (temp_second)
		{
			if (temp_first->number > temp_second->number)
				position++;
			temp_second = temp_second->next;
		}
		temp_first->id = position;
		temp_first = temp_first->next;
		lst_size--;
	}
}

int	ft_bits(int lst_size)
{
	int	i;

	i = 0;
	while ((lst_size - 1) >> i != 0)
		i++;
	return (i);
}

void	ft_radix_start(t_stack **lst_a, t_stack **lst_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stacksize((*lst_a));
	ft_node_id_assignment(lst_a);
	ft_radix_iteration(i, size, lst_a, lst_b);
}

void	ft_radix_iteration(int i, int size, t_stack **lst_a, t_stack **lst_b)
{
	int	j;

	while (i < ft_bits(size))
	{
		j = -1;
		while (j++ < size)
		{
			if (((*lst_a)->id >> i & 1) == 1)
				ft_ra(lst_a, "ra\n");
			else if (((*lst_a)->id >> i & 1) == 0)
				ft_pb(lst_a, lst_b, "pb\n");
		}
		while (ft_stacksize(*lst_b) != 0)
			ft_pa(lst_a, lst_b, "pa\n");
		i++;
	}
}
