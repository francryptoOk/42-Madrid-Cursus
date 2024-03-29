/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:28 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/05 15:39:33 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	ft_error_msg(char *msg)
{
	ft_printf("%s", msg);
	write(2, "\n", 1);
	return (1);
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

// -to print liberations, between lines 33/34)-
// ft_printf("Liberando %s\n", arr[i]);