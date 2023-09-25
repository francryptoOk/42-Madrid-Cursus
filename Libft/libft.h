/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:19:54 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/25 15:13:57 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(char *str);
void			*ft_memset(void *dest, int c, size_t count);
void			*ft_bzero(void *dest, size_t count);
//void			*ft_memcpy(void *dest, const void *src, size_t count);
//void			*ft_memmove(void *dest, const void *src, size_t count);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
//unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
//int				ft_toupper(int c);
//int				ft_tolower(int c);
//char*			ft_strchr(const char *str, int c);
//char*			ft_strrchr(const char *str, int c);
//int				ft_strncmp(char *s1, char *s2, unsigned int n);

#endif