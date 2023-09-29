/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:19:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:52:31 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(char *str);
void			*ft_memset(void *dest, int c, size_t count);
void			*ft_bzero(void *dest, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t count);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(char *s1, char *s2, size_t n);
//	ft_memchr
//	ft_memcmp
//	ft_strnstr
//int			ft_atoi(char *str)
//void			*calloc(size_t number, size_t size)
//	ft_strdup
//	ft_substr
//	ft_strjoin
//	ft_strtrim
//	ft_split
//	ft_itoa
//	ft_strmapi
//	ft_striteri
//	ft_putchar_fd
//	ft_putstr_fd
//	ft_putendl_fd
//	ft_putnbr_fd

#endif