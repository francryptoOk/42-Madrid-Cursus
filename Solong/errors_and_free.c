/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:28 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/14 14:51:28 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	ft_error(int e)
{
	write(2, "Error\n", 6);
	return (e);
}

void	*ft_arr_free(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	return (NULL);
}

// -to print liberations, between lines 32/33)-
// ft_printf("Liberando %s\n", arr[i]);