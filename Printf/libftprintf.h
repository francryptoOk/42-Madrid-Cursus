/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:49 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/15 18:01:41 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar_mod(char c, int printcount);
int	ft_putstr_mod(char *str, int printcount);
//int	ft_puthex(unsigned long long h, int printcount);
//int	ft_putptr(void *ptr, int printcount);
int	ft_putnbr_mod(int nb, int printcount);
int	ft_checking_the_format(char *str, int i, va_list args, int printcount);
int	ft_printf(char const *str, ...);

#endif