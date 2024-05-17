/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:49 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/16 17:43:35 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar_mod(char c, int printcount);
int	ft_putstr_mod(char *str, int printcount);
int	ft_puthex_low(unsigned long long h, int printcount);
int	ft_puthex_upp(unsigned long long h, int printcount);
int	ft_putptr(void *ptr, int printcount);
int	ft_putnbr_mod(int nb, int printcount);
int	ft_putnbr_mod_unsigned(unsigned int nb, int printcount);
int	ft_checking_the_format(char *str, int i, va_list args, int printcount);
int	ft_printf(char const *str, ...);

#endif