/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/26 14:49:41 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_freedom(char **p)
{
	if (p && *p)
		free (*p);
	*p = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*readed;
	char	*temp;
	int		len_bool;

	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (ft_freedom(&readed), NULL);
	len_bool = 1;
	while (!ft_strchr_mod(buffer, '\n'))
	{
		len_bool = read(fd, readed, BUFFER_SIZE);
		if (len_bool == -1)
			return (ft_freedom(&readed), NULL);
		readed[len_bool] = '\0';
		if (readed[0] == '\0')
			return (ft_freedom(&readed), buffer);
		temp = ft_strjoin_mod(buffer, readed);
		buffer = temp;
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
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	i++;
	result = (char *)malloc(ft_strlen_to_delimiter(buffer, '\0') - i + 1);
	if (!result)
		ft_freedom(&result);
	j = 0;
	while (buffer[i])
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
	static char	*buffer;
	char		*line;
	int			buffer_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		ft_freedom(&buffer);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		ft_freedom(&buffer);
	buffer_len = ft_strlen_to_delimiter(buffer, '\0');
	line = ft_substr_mod(buffer, 0, ft_strlen_to_delimiter(buffer, '\n') + 1);
	if (!line)
		ft_freedom(&line);
	buffer = remove_line(buffer);
	return (line);
}

int main(void)
{
	int fd;
	int line = 1;
	char *lines;
	fd = open("Pruebas.txt", O_RDONLY);

	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	printf("%s", lines = get_next_line(fd));
	return (0);
}
