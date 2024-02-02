/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:45:06 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/02 17:12:35 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int e)
{
	write(2, "Error\n", 6);
	return (e);
}

void	*ft_arr_free(char **splt)
{
	int	i;

	i = 0;
	while (splt && splt[i])
	{
		ft_printf("Liberando %s\n", splt[i]);
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

/*void	t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	&(*stack)->next);
	free(*stack);
	*stack = NULL;
}*/
