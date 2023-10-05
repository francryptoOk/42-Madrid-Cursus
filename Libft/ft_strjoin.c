/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:11 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/05 15:17:48 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*strnew;

	i = 0;
	j = 0;
	len1 = (ft_strlen(s1)) - 1;
	len2 = (ft_strlen(s2)) - 1;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strnew = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strnew)
		return (NULL);
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strnew[i + j] = s2[j];
		j++;
	}
	strnew [i + j] = '\0';
	return (strnew);
}
/**
 * The function `ft_strjoin` concatenates two strings `s1` and `s2` into a
 * new string.
 * 
 * @param s1 A pointer to a constant character string (string 1)
 * @param s2 The parameter `s2` is a pointer to a constant character string.
 * 
 * @return a pointer to a newly allocated string that is the concatenation of
 * the two input strings, s1 and s2.
 */