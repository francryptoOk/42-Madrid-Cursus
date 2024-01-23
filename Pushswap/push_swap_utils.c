/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/23 14:44:51 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol_int(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result * sign);
}

void	ft_stack_add(int nb, t_stack **new)
{
	t_stack	*aux;

	aux = (t_stack *)malloc(sizeof(t_stack *));
	if (!aux)
		free(aux);
	aux->number = nb;
	aux->next = NULL;
	if (!(*new))
		*new = aux;
	else
		ft_stack_last(*new)->next = aux;
}

t_stack	*ft_stack_second_last(t_stack *lst)
{
	t_stack	*prev;

	if (!lst || !lst->next)
		return (NULL);
	while (lst->next != NULL)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

t_stack	*ft_stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
