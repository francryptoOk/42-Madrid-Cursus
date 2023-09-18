/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:12 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/18 17:08:42 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_bzero(void *dest, size_t c)
{
	unsigned char	*destino;

	destino = dest;
	while (c != 0)
	{
		destino[c] = 0;
		c--;
	}
	return (destino);
}
