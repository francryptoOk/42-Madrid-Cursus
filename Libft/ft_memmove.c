/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:36:25 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/18 21:40:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t count)
{
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	if (destination < source)
		while (count != 0)
		{
			*destination++ = *source++;
			count--;
		}
	else
	{
		destination += count;
		source += count;
		while (count != 0)
		{
			*destination-- = *source--;
			count--;
		}
	}
}
/*ARREGLAR estaría mal el ELSE porque necesitas pre-decremento no post-decremento
porque destination += count apunta afuera de la memoria que queres mover
y *destination-- = *source-- te va a mover un byte por fuera del size*/