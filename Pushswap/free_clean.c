/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:45:06 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 14:49:08 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_freedom(char **splt)
{
	int	index;

	index = 0;
	while (splt && splt[index])
	{
		ft_printf("Liberando %s\n", splt[index]);
		free(splt[index++]);
	}
	if (splt)
		free(splt);
	*splt = NULL;
	return (splt);
}

void	ft_stack_clear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_stack_clear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}
