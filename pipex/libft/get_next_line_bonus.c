/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:21:05 by fsantill          #+#    #+#             */
/*   Updated: 2024/06/20 15:10:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freedom(char **p)
{
	if (p && *p)
		free (*p);
	*p = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*readed;
	int		aux;

	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (ft_freedom(&buffer), NULL);
	while (!ft_strchr_mod(buffer, '\n'))
	{
		aux = read(fd, readed, BUFFER_SIZE);
		if (aux == -1)
			return (ft_freedom(&readed), ft_freedom(&buffer), NULL);
		readed[aux] = '\0';
		if (readed[0] == '\0')
			return (ft_freedom(&readed), buffer);
		buffer = ft_strjoin_mod(buffer, readed);
		if (!buffer)
			return (ft_freedom(&readed), ft_freedom(&buffer), NULL);
	}
	ft_freedom(&readed);
	return (buffer);
}

static char	*remove_line(char *buffer)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	result = (char *)malloc((ft_strlen_to_limit(buffer, '\0') \
	- i + 1) * sizeof(char));
	if (!result)
		return (ft_freedom(&buffer), NULL);
	j = 0;
	while (buffer[i] != '\0')
	{
		result[j] = buffer[i];
		i++;
		j++;
	}
	result[j] = '\0';
	ft_freedom(&buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd] == NULL || !ft_strchr_mod(buffer[fd], '\n'))
	{
		buffer[fd] = ft_read(fd, buffer[fd]);
		if (!buffer[fd])
			return (NULL);
	}
	if (ft_strchr_mod(buffer[fd], '\n'))
		line = ft_substr_mod(buffer[fd], 0, \
		ft_strlen_to_limit(buffer[fd], '\n') + 1);
	else
		line = ft_substr_mod(buffer[fd], 0, \
		ft_strlen_to_limit(buffer[fd], '\0') + 1);
	if (!line)
		return (NULL);
	buffer[fd] = remove_line(buffer[fd]);
	if (buffer[fd][0] == '\0')
		ft_freedom(&buffer[fd]);
	return (line);
}

/**
 * The function `get_next_line` reads a file descriptor line by line and
 * returns each line as a string.
 * 
 * @param p p is a pointer to a pointer to a character (char **).
 * It is used to store the address of a character pointer.
 * 
 * @return The function `get_next_line` returns a line of text read from
 * a file descriptor.
 */
