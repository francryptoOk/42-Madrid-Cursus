/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:45:06 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/12 16:01:07 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q push_swap");
}

int	ft_error(int e)
{
	ft_printf("Error\n");
	return (e);
}

void	*ft_arr_free(char **splt)
{
	int	i;

	i = 0;
	while (splt && splt[i])
	{
		free(splt[i]);
		i++;
	}
	if (splt)
		free(splt);
	return (NULL);
}

void	ft_stk_free(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

// -to print liberations, between lines 32/33)-
// ft_printf("Liberando %s\n", splt[i]);