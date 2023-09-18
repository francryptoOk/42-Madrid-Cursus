/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:36:25 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/18 18:42:20 by fsantill         ###   ########.fr       */
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
