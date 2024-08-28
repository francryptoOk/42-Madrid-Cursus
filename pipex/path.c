/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:17:08 by fsantill          #+#    #+#             */
/*   Updated: 2024/08/28 12:18:57 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path(char **env)
{
	int		i;
	char	**route;

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

char	*ft_valid_cmd_path(char **route, char *argv)
{
	char	*path_with_bar;
	char	*path_with_cmd;
	int		i;

	i = 0;
	if ((argv[0] == '.' && argv[1] == '/') || argv[0] == '/')
	{
		if (access(argv, X_OK) == 0)
			return (argv);
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
