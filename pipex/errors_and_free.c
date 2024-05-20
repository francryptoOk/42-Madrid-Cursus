/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:28 by fsantill          #+#    #+#             */
/*   Updated: 2024/05/20 09:58:33 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

void	ft_exit_error_msg(char *msg)
{
	ft_printf("%s", msg);
	write(2, "\n", 1);
	exit (EXIT_FAILURE);
}

void	ft_exit_perror_msg(char *msg)
{
	perror(msg);
	write(2, "\n", 1);
	exit (EXIT_FAILURE);
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