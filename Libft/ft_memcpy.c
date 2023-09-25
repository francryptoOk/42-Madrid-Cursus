/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:23:23 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/25 17:49:04 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*destiny;
	unsigned char	*source;
	size_t			i;

	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (destiny == 0 && source == 0)
		return (0);
	while (i < count)
	{
		destiny[i] = source[i];
		i++;
	}
	return (destiny);
}
