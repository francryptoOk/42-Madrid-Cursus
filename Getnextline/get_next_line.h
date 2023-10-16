/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:42 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/16 15:14:40 by fsantill         ###   ########.fr       */
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
int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t count);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *dest, size_t count);
void	*ft_calloc(size_t number, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif