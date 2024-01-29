/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:54 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/29 14:48:08 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_freedom(char **p)
{
	if (p && *p)
		free (*p);
	*p = NULL;
	return (NULL);
}

int	numbers_in_order(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->number < lst->next->number)
			lst = lst->next;
		else
			return (0);
	}
	return (ft_printf("Numbers in order\n"), 1);
}

long long	ft_atoll_int(char *str)
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

	aux = (t_stack *)malloc(sizeof(t_stack));
	if (!aux)
	{
		free(aux);
		ft_printf("Stack add Mem Alloc error");
	}
	aux->number = nb;
	aux->next = NULL;
	if (!(*new))
		*new = aux;
	else
		ft_stack_last(*new)->next = aux;
}
