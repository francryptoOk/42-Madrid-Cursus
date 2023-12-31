/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:42 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/31 11:45:22 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen_to_limit(char *str, int delimiter);
char	*ft_strchr_mod(char *str, int c);
char	*ft_strdup_mod(char *str);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_substr_mod(char *s, unsigned int start, size_t len);

#endif