/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:12 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:33 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[length] != '\0' && length < (size - 1))
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (i);
}
/**
 * The function `ft_strlcpy` copies a string from `src` to `dest` up to a
 * specified size, and returns the length of the source string.
 * 
 * @param dest A pointer to the destination string where the
 * copied string will be stored.
 * @param src A pointer to the source string that needs to be copied.
 * @param size The size parameter represents the size of the destination
 * buffer, which is the maximum number of characters that can be copied
 * from the source string to the destination string.
 * 
 * @return the length of the source string.
 */