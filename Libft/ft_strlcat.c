/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:13 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:01 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_runstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	ori_dest_length;

	ori_dest_length = ft_runstr(dest);
	dest_length = ori_dest_length;
	src_length = ft_runstr(src);
	i = 0;
	if (size == 0)
		return (src_length);
	if (dest_length > size)
		return (src_length + size);
	while (src[i] != '\0' && dest_length < (size - 1))
	{
		dest[dest_length] = src[i];
		i++;
		dest_length++;
	}
	dest[dest_length] = 0;
	return (src_length + ori_dest_length);
}
/**
 * The ft_strlcat function concatenates two strings, ensuring that the
 * resulting string does not exceed a specified size.
 * 
 * @param str The parameter `str` is not used in the code provided.
 * 
 * @return The function `ft_strlcat` returns the total length of the
 * concatenated string, which is the sum of the original length of the
 * destination string (`ori_dest_length`) and the length of the source
 * string (`src_length`).
 */