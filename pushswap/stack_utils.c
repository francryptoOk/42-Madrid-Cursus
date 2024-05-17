/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:24:14 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 16:41:56 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	ft_min_node(t_stack *node)
{
	int	min_node;

	min_node = INT_MAX;
	if (!node)
		return (1);
	while (node)
	{
		if (node->number < min_node)
			min_node = node->number;
		node = node->next;
	}
	return (min_node);
}

int	ft_max_node(t_stack *node)
{
	int	max_node;

	max_node = INT_MIN;
	if (!node)
		return (1);
	while (node)
	{
		if (node->number > max_node)
			max_node = node->number;
		node = node->next;
	}
	return (max_node);
}

t_stack	*ft_stack_second_last(t_stack *node)
{
	if (!node || !node->next)
		return (NULL);
	while (node->next && node->next->next)
		node = node->next;
	return (node);
}

t_stack	*ft_stack_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
