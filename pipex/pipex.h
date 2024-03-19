/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/19 12:51:42 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"

# define END_READ 0		//index pipe for read
# define END_WRITE 1	//index pipe for write

typedef struct s_pip
{
	int	fd[2];
}					t_pip;

void	ft_leaks(void);
void	ft_exit_error_msg(char *msg);
void	ft_exit_perror_msg(char *msg);
void	*ft_arr_free(char **arr);
void	ft_son(char **argv, t_pip father, char **env);
void	ft_father(char **argv, t_pip father, char **env);

#endif