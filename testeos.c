/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testeos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:19:48 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/15 11:48:02 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

/*int	test_isascii(void)
{
	if (ft_isascii('............') == 0)
		return (0);
	else
		return (1);
}*/

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
	return (0);
}
