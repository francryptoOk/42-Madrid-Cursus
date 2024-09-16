/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/09/16 11:50:32 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "libft/libft.h"

//typedef struct s_pip
//{
//	int	fd[2];
//}					t_pip;

void	ft_leaks(void);
void	ft_exit_msg(char *msg, int errorvalue);
void	*ft_arr_free(char **arr);

#endif