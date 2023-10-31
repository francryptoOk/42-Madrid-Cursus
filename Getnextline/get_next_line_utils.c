/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:16 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/31 11:34:06 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_to_delimiter(char *str, int delimiter)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != delimiter)
		i++;
	return (i);
}

char	*ft_strchr_mod(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0' || *str == (unsigned char)c)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup_mod(char *str)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen_to_delimiter(str, '\0');
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char			*dst;
	unsigned int	len_total;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strdup_mod(s2));
	len_total = ft_strlen_to_delimiter(s1, '\0') + ft_strlen_to_delimiter(s2, '\0');
	dst = (char *)malloc((len_total + 1) * sizeof(char));
	if (!dst)
		return (free(&dst), NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

char	*ft_substr_mod(char *s, unsigned int start, size_t len)
{
	size_t			slen;
	unsigned int	i;
	char			*dest;

	slen = ft_strlen_to_delimiter(s, '\0');
	if (start > slen)
		return (free(&s), NULL);
	if (len > slen - start)
		len = slen - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !dest)
		return (free(&s), NULL);
	i = 0;
	while (start < slen && i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
