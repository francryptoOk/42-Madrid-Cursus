/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/06/20 14:40:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	./pipex 	infile	com1	|	com2	outfile
	0			1		2			3		4			<- argv Nº
*/

#include "pipex.h"

void	ft_execute(char **argv, t_pip father, char **env)
{
//	if (ft_strncmp(PATH))
	ft_split((const char *)argv, ' ');
	ft_split((const char *)argv, '/');
	ft_exit_msg("Error\n\t• Command not found", 1);
}

void	ft_son(char **argv, t_pip father, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem open outfile", 1);
	dup2(fd, 0);
	dup2(father.fd[1], 1);
	close(father.fd[0]);
	close(fd);
	execve(argv[2], &argv[2], env);
	ft_exit_msg("execve", 1);
}

void	ft_father(char **argv, t_pip father, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem open infile", 1);
	dup2(fd, 1);
	dup2(father.fd[0], 0);
	close(father.fd[1]);
	close(fd);
	execve(argv[3], &argv[3], env);
	ft_exit_msg("execve", 1);
}

int	main(int argc, char **argv, char **env)
{
	t_pip	father;
	pid_t	pid;

	if (argc == 5 && argv)
	{
		if (pipe(father.fd) == -1)
			ft_exit_msg("Error\n\t• Pipe, failed FD's", 1);
		pid = fork();
		if (pid < 0)
			ft_exit_msg("Error\n\t• Fork, cannot duplicate process", 1);
		else if (pid == 0)
			ft_son(argv, father, env);
		else
		{
			wait(NULL);
			ft_father(argv, father, env);
		}
		return (0);
	}
	else
		ft_exit_msg("Error\n\t• Invalid arguments", 0);
}
