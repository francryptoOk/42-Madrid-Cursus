/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:36:25 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/25 18:14:33 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*destiny;
	unsigned char	*source;
	size_t			i;

	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	if (destiny == 0 || source == 0)
		return (0);
	if (destiny < source)
		while(i < count)
		{
			destiny[i] = source[i];
			i++;
		}
	else
	{
		i = count - 1;
		destiny[i] = source[i];
		i--;
	}
	return (destiny);
}
