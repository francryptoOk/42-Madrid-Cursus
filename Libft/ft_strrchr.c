/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/03 11:15:30 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)&str[i + 1]);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
/**
 * The function ft_strrchr searches for the last occurrence of a character
 * in a string and returns a pointer to that character.
 * 
 * @param str A pointer to the string in which to search for the character.
 * @param c The parameter "c" is the character that we are searching
 * for in the string.
 * 
 * @return a pointer to the last occurrence of the character 'c' in the
 * string 'str'. If 'c' is not found, it returns NULL.
 */