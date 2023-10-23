/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:16 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/23 13:20:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_to_delimiter(const char *str, int delimiter)
{
	int	i;

	i = 0;
	if (!str || !delimiter)
		return (-1);
	while (str[i] != delimiter)
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	int					i;
	const unsigned char	caux = (unsigned char)c;

	i = ft_strlen_to_delimiter(str, '\0') - 1;
	if (caux == '\0')
		return ((char *)&str[i + 1]);
	while (i >= 0)
	{
		if (str[i] == caux)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strdup_mod(const char *str)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen_to_delimiter(s1, '\0') + ft_strlen_to_delimiter(s2, '\0');
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
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
	return (dst);
}

char	*ft_substr_mod(char const *s, unsigned int start, size_t len)
{
	size_t			slen;
	unsigned int	i;
	char			*dest;

	slen = ft_strlen_to_delimiter(s, '\0');
	if (start > slen)
		return (NULL);
	if (len > slen - start)
		len = slen - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !dest)
		return (NULL);
	i = 0;
	while (start < slen && i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
