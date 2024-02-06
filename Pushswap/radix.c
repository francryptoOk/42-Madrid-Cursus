/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francrypto <francrypto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:40:24 by francrypto        #+#    #+#             */
/*   Updated: 2024/02/06 16:35:35 by francrypto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
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

void	ft_radix(t_stack **lst_a, t_stack **lst_b)
{
	int	i;
	int	j;
	int	lst_size;

	i = 0;
	lst_size = ft_stacksize((*lst_a));
	ft_node_id_assignment(lst_a);
	while (i < ft_bits(lst_size))
	{
		j = 0;
		while (j < lst_size)
		{
			if (((*lst_a)->id >> i & 1) == 1)
			{
				ft_ra(lst_a);
				ft_printf("ra\n");
			}
			else if (((*lst_a)->id >> i & 1) == 0)
			{
				ft_pb(lst_a, lst_b);
				ft_printf("pb\n");
			}
			j++;
		}
		while (ft_stacksize(*lst_b) > 0)
		{
			ft_pa(lst_b, lst_a);
			ft_printf("pa\n");
		}
		i++;
	}
}
