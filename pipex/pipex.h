/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/07/01 12:12:54 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"

# define END_IN_READ 0		//index pipe for read
# define END_OUT_WRITE 1	//index pipe for write

typedef struct s_pip
{
	int	fd[2];
}					t_pip;

void	ft_leaks(void);
void	ft_exit_msg(char *msg, int perrorbool);
void	*ft_arr_free(char **arr);
char	**ft_path(char **env);
char	*ft_valid_cmd_path(char **route, char *argv);
void	ft_son(char **argv, t_pip father, char **env);
void	ft_father(char **argv, t_pip father, char **env);

#endif