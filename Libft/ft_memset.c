/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:37:27 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/18 17:01:03 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*destino;

	destino = dest;
	while (count != 0)
	{
		destino[count] = (unsigned char)c;
		count--;
	}
	return (destino);
}
