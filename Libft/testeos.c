/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testeos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:19:48 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/25 15:13:53 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	test_isalpha(void)
{
	if (ft_isalpha('a') == 0)
		return (0);
	if (ft_isalpha('z') == 0)
		return (0);
	if (ft_isalpha('A') == 0)
		return (0);
	if (ft_isalpha('Z') == 0)
		return (0);
	if (ft_isalpha('F') == 0)
		return (0);
	if (ft_isalpha('r') == 0)
		return (0);
	else
		return (1);
}

int	test_isdigit(void)
{
	if (ft_isdigit('0') == 0)
		return (0);
	if (ft_isdigit('9') == 0)
		return (0);
	if (ft_isdigit('5') == 0)
		return (0);
	else
		return (1);
}

int	test_isalnum(void)
{
	if (ft_isalnum('a') == 0)
		return (0);
	if (ft_isalnum('z') == 0)
		return (0);
	if (ft_isalnum('A') == 0)
		return (0);
	if (ft_isalnum('Z') == 0)
		return (0);
	if (ft_isalnum('F') == 0)
		return (0);
	if (ft_isalnum('r') == 0)
		return (0);
	if (ft_isalnum('0') == 0)
		return (0);
	if (ft_isalnum('9') == 0)
		return (0);
	if (ft_isalnum('5') == 0)
		return (0);
	else
		return (1);
}

int	test_isascii(void)
{
	if (ft_isascii(127) == 1)
		return (1);
	else
		return (0);
}

int	test_isprint(void)
{
	if (ft_isprint(' ') == 0)
		return (0);
	if (ft_isprint('/') == 0)
		return (0);
	if (ft_isprint('~') == 0)
		return (0);
	else
		return (1);
}

int	test_strlen(void)
{
	if (ft_strlen("hola") != 4)
		return (0);
	else
		return (1);
}

int	test_memset(void)
{
	char	mem1[10] = "hola, que?";
	char	mem2[10] = "hola, que?";
	int		i = 0;

	memset(mem1, '+', 4);
	ft_memset(mem2, '+', 4);
	if (mem1[i] == mem2[i])
	{
		while (i != '\0')
			i++;
		return (1);
	}
	else
		return (0);
}

int	test_bzero(void)
{
	char	mem1[10] = "hola, que?";
	char	mem2[10] = "hola, que?";
	int		i = 0;

	bzero(mem1, 4);
	ft_bzero(mem2, 4);
	if (mem1[i] == mem2[i])
	{
		while (i != '\0')
			i++;
		return (1);
	}
	else
		return (0);
}

int	test_strlcpy(void)
{
	char	str1[10] = "hola, que?";
	int		len1 = 9;
	int		len2 = 3;

	len1 = strlcpy(str1, "chau", sizeof(str1));
	len2 = ft_strlcpy(str1, "chau", sizeof(str1));
	if (len1 == len2)
		return (1);
	else
		return (0);
}

int	main(void)
{
	if (test_isalpha() == 1)
		printf("isalpha = OKey! :D\n");
	else
		printf("isalpha = KnOckout! :(\n");
	if (test_isdigit() == 1)
		printf("isdigit = OKey! :D\n");
	else
		printf("isdigit = KnOckout! :(\n");
	if (test_isalnum() == 1)
		printf("isalnum = OKey! :D\n");
	else
		printf("isalnum = KnOckout! :(\n");
	if (test_isascii() == 1)
		printf("isascii = OKey! :D\n");
	else
		printf("isascii = KnOckout! :(\n");
	if (test_isprint() == 1)
		printf("isprint = OKey! :D\n");
	else
		printf("isprint = KnOckout! :(\n");
	if (test_strlen() == 1)
		printf("strlen = OKey! :D\n");
	else
		printf("strlen = KnOckout! :(\n");
	if (test_memset() == 1)
		printf("memset = OKey! :D\n");
	else
		printf("memset = KnOckout! :(\n");
	if (test_bzero() == 1)
		printf("bzero = OKey! :D\n");
	else
		printf("bzero = KnOckout! :(\n");
	if (test_strlcpy() == 1)
		printf("strlcpy = OKey! :D\n");
	else
		printf("strlcpy = KnOckout! :(\n");
	return (0);
}
