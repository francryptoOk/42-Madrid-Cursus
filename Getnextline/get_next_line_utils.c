/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:16 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/16 17:26:00 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' || *str == (char)c)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

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

char	*ft_strdup(const char *str)
{
	int		length;
	char	*ptr;

	length = ft_strlen(str);
	ptr = malloc (length + 1);
	if (ptr == 0)
		return (NULL);
	ft_memcpy(ptr, str, length);
	ptr[length] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*strnew;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strnew = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strnew)
		return (NULL);
	ft_memcpy(strnew, s1, len1);
	ft_memcpy(strnew + len1, s2, len2);
	strnew [len1 + len2] = '\0';
	return (strnew);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_i;
	char	*sub_s;

	i = start;
	sub_i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[i] != '\0' && sub_i < len)
	{
		sub_s[sub_i] = s[i];
		sub_i++;
		i++;
	}
	sub_s[sub_i] = '\0';
	return (sub_s);
}
