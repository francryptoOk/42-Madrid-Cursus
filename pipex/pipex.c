/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/08/28 12:22:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	route_absolute_relative(char *argv, char ***cmdflagsplit,
	char **validcmd, char **env)
{
	char	**route;

	if ((ft_strncmp(argv, "/", 1) != 0) && (ft_strncmp(argv, "./", 2) != 0)
		&& (ft_strncmp(argv, "../", 3) != 0))
	{
		route = ft_path(env);
		*cmdflagsplit = ft_split(argv, ' ');
		*validcmd = ft_valid_cmd_path(route, *cmdflagsplit[0]);
	}
	else
	{
		*cmdflagsplit = ft_split(argv, ' ');
		*validcmd = ft_strdup(*cmdflagsplit[0]);
	}
}

void	ft_son_one(char **argv, t_pip father, char **env)
{
	int		fd;
	char	**cmdflagsplit;
	char	*validcmd;

	close(father.fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem opening infile", 1);
	dup2(fd, STDIN_FILENO);
	dup2(father.fd[1], STDOUT_FILENO);
	close(fd);
	route_absolute_relative(argv[2], &cmdflagsplit, &validcmd, env);
	execve(validcmd, cmdflagsplit, env);
	ft_arr_free(cmdflagsplit);
	free(validcmd);
	ft_exit_msg("Error\n\t• execve failed", 1);
}

void	ft_son_two(char **argv, t_pip father, char **env)
{
	int		fd;
	char	**cmdflagsplit;
	char	*validcmd;

	close(father.fd[1]);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem opening outfile", 1);
	dup2(fd, STDOUT_FILENO);
	dup2(father.fd[0], STDIN_FILENO);
	close(fd);
	route_absolute_relative(argv[3], &cmdflagsplit, &validcmd, env);
	execve(validcmd, cmdflagsplit, env);
	ft_arr_free(cmdflagsplit);
	free(validcmd);
	ft_exit_msg("Error\n\t• execve failed", 1);
}

int	main(int argc, char **argv, char **env)
{
	t_pip	father;
	pid_t	pid;
	int		status;
	int		father_pid;

	if (argc != 5)
		ft_exit_msg("Error\n\t• Invalid arguments", -1);
	if (pipe(father.fd) == -1)
		ft_exit_msg("Error\n\t• Pipe failed", 1);
	pid = fork();
	ft_pid_fork_error(pid);
	if (pid > 0)
		father_pid = pid;
	if (pid == 0)
		ft_son_one(argv, father, env);
	pid = fork();
	ft_pid_fork_error(pid);
	if (pid > 0)
		father_pid = pid;
	if (pid == 0)
		ft_son_two(argv, father, env);
	waitpid(-1, NULL, 0);
	close(father.fd[0]);
	close(father.fd[1]);
	return (waitpid(father_pid, &status, 0), WEXITSTATUS(status));
}
