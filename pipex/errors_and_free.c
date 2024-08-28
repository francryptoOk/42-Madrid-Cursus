/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:28 by fsantill          #+#    #+#             */
/*   Updated: 2024/08/28 12:17:18 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

void	ft_pid_fork_error(pid_t pid)
{
	if (pid == -1)
		ft_exit_msg("Error\n\t• Fork cannot duplicate process", 1);
}

void	ft_exit_msg(char *msg, int errorvalue)
{
	if (errorvalue >= 0)
		perror(msg);
	else
		ft_printf("%s", msg);
	write(2, "\n", 1);
	exit (errorvalue);
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
