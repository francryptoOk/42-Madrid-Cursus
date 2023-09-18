/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:23:23 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/18 18:42:12 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*destination;
	const unsigned char	*source;
	
	while (count != 0)
	{
		destination[count] = source[count];
		count--;
	}
	return (destination);
}
