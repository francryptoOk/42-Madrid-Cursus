/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/14 16:16:39 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pip	father;
	pid_t	pid;

	if (argc == 5 && argv)
	{
		if (pipe(father.fd) == -1)
			ft_exit_perror_msg("Error\n\t• Pipe ");
		pid = fork();
		if (pid == -1)
			ft_exit_perror_msg("Error\n\t• Fork ");
		else if (pid == 0)
		{
			close(father.fd[END_WRITE]);
			dup2(father.fd[END_READ], STDOUT_FILENO);
			close(father.fd[END_READ]);
			execve(argv[3], argv + 3, env);
			perror("execve");
		}
		else
		{
			close(father.fd[END_READ]);
			dup2(father.fd[END_WRITE], STDOUT_FILENO);
			close (father.fd[END_WRITE]);
			execve(argv[2], argv + 2, env);
			perror("execve");
		}
		return (0);
	}
	else
		ft_exit_error_msg("Error\n\t• Invalid arguments");
}
