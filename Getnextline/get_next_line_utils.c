/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:16 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/13 11:45:18 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
