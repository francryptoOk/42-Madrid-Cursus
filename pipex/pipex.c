/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/07/15 13:38:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	./pipex 	infile	com1	|	com2	outfile
	0			1		2			3		4			<- argv Nº
*/

/*	
	* infile:
	ej. cat < infile (usa O_RDONLY, lee el contenido si existe, sino error)

	* here_doc:
	ej. cat << EOF (end of file) (usa el FD temporal donde almacena
	lo que se escribe por consola)
	
	* trunc:
	ej. cat > outfile (usa O_TRUNC, crea el archivo o lo elimina si existe
	para crearlo de nuevo con ese contenido)
	
	* append:
	ej. cat >> outfile (usa O_APPEND, crea el archivo o añade el
	contenido al ya existente)

	si hay varios infiles o varios outfiles SOLO va a utilizar el ULTIMO
*/

#include "pipex.h"

char	**ft_path(char **env)
{
	int	i;
	char **route;
	
	i = 0;
	route = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen("PATH=")))
		{
			route = ft_split(env[i] + ft_strlen("PATH="), ':');
			return (route);
		}
		i++;
	}
	ft_exit_msg("Error\n\t• Path/Route not found", 127);
	return (NULL);
}

//	i = -1;
//	while (route[++i])
//		ft_printf("%s\n", route[i]);

char	*ft_valid_cmd_path(char **route, char *argv)
{
	char *path_with_bar;
	char *path_with_cmd;
	int	i;

	i = 0;
	if (argv[0] == '.' && argv[1] == '/')
	{
		if (access(argv, X_OK) == 0)
			return (argv);
	}
	if (argv[0] == '/')
	{
		if (access(argv, X_OK) == 0)
			return (argv);
		else
			ft_exit_msg("Error\n\t• Invalid cmd\n", 127);
	}
	while (route[i])
	{
		path_with_bar = ft_strjoin(route[i], "/");
		path_with_cmd = ft_strjoin(path_with_bar, argv);
		free(path_with_bar);
		if (access(path_with_cmd, X_OK) == 0)
			return (path_with_cmd);
		free(path_with_cmd);
		i++;
	}
	ft_exit_msg("Error\n\t• Invalid cmd on Path/Route", 127);
	return (NULL);
}

void	ft_son_one(char **argv, t_pip father, char **env)
{
	int	fd;
	char	**route;
	char	**cmdflagsplit;
	char	*validcmd;

	close(father.fd[0]); //I don't use this reading FD in child process, so it's better closing
	fd = open(argv[1], O_RDONLY); //open infile in read only mode
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem opening infile", 1);
	dup2(fd, STDIN_FILENO); //Here I change the input from standard (terminal) to FD (infile)
	dup2(father.fd[1], STDOUT_FILENO); //Here I change the output from standard to FD[1] (in structure)
	close(fd); //I ended using the FD (the open infile), so it's better closing
	route = ft_path(env);
	cmdflagsplit = ft_split(argv[2], ' ');
	validcmd = ft_valid_cmd_path(route, cmdflagsplit[0]);
	execve(validcmd, cmdflagsplit, env); //First command execution
	ft_arr_free(route);
	ft_arr_free(cmdflagsplit);
	free(validcmd);
	ft_exit_msg("Error\n\t• execve failed", 1);
}

void	ft_son_two(char **argv, t_pip father, char **env)
{
	int		fd;
	char	**route;
	char	**cmdflagsplit;
	char	*validcmd;

	close(father.fd[1]); //I don't use this writing FD in parent process, so it's better closing
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666); // open outfile in write only, trunc file (erasing old data in it) or create new file (if doesn't exist), 0666 for all permitions
	if (fd == -1)
		ft_exit_msg("Error\n\t• Problem opening outfile", 1);
	dup2(fd, STDOUT_FILENO); //Here I change the output from standard (terminal) to FD (outfile)
	dup2(father.fd[0], STDIN_FILENO); //Here I change the input from standard to FD[0] (in structure)
	close(fd); //I ended using the FD (the open outfile), so it's better closing
	route = ft_path(env);
	cmdflagsplit = ft_split(argv[3], ' ');
	validcmd = ft_valid_cmd_path(route, cmdflagsplit[0]);
	execve(validcmd, cmdflagsplit, env); //Second command execution
	ft_arr_free(route);
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
	waitpid(father_pid, NULL, 0);
	pid = fork();
	ft_pid_fork_error(pid);
	if (pid > 0)
		father_pid = pid;
	if (pid == 0)
		ft_son_two(argv, father, env);
	close(father.fd[0]);
	close(father.fd[1]);
	return (waitpid(father_pid, &status, 0), WEXITSTATUS(status));
}

//		ft_printf("fd0: %i fd1: %i\n", father.fd[0], father.fd[1]);