/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/06/27 12:13:59 by fsantill         ###   ########.fr       */
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

	close(father.fd[0]); //I don't use this reading FD in child process, so it's better closing
	fd = open(argv[1], O_RDONLY); //open in read only
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem open infile", 1);
	dup2(fd, STDIN_FILENO); //Here I change the input from standard (terminal) to FD (infile)
	dup2(father.fd[1], STDOUT_FILENO); //Here I change the output from standard to FD[1] (in structure)
	close(fd); //I ended using the FD (the open infile), so it's better closing
	execve(argv[2], &argv[2], env); //First command execution
	ft_exit_msg("execve", 1); //If execve fails, exit with perror
}

void	ft_father(char **argv, t_pip father, char **env)
{
	int	fd;

	close(father.fd[1]); //I don't use this writing FD in parent process, so it's better closing
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666); // open in write only, trunc file (erasing old data in it) or create new file (if doesn't exist), 0666 for all permitions
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem open outfile", 1);
	dup2(fd, STDOUT_FILENO); //Here I change the output from standard (terminal) to FD (infile)
	dup2(father.fd[0], STDIN_FILENO); //Here I change the output from standard to FD[0] (in structure)
	close(fd); //I ended using the FD (the open outfile), so it's better closing
	execve(argv[3], &argv[3], env); //Second command execution
	ft_exit_msg("execve", 1); //If execve fails, exit with perror
}

int	main(int argc, char **argv, char **env)
{
	t_pip	father;
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(father.fd) == -1)
			ft_exit_msg("Error\n\t• Pipe, failed FD's", 1);
		return (0);
		pid = fork();
		if (pid == -1)
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

//		ft_printf("fd0: %i fd1: %i\n", father.fd[0], father.fd[1]);