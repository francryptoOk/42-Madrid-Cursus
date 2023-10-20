/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/20 17:29:20 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_to_delimiter(const char *str, int delimiter)
{
	int	i;

	i = 0;
	if (!str || !delimiter)
		return (-1);
	while (str[i] != delimiter)
		i++;
	return (i);
}

static char	*ft_freedom(char *read, char *buf, char *line)
{
	free (read);
	free (buf);
	free (line);
	read = NULL;
	buf = NULL;
	line = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*readed;
	int		len_bool;

	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (ft_freedom(readed, buffer, NULL));
	len_bool = 1;
	while (len_bool > 0 && !ft_strrchr(buffer, '\n'))
	{
		len_bool = read(fd, readed, BUFFER_SIZE);
		if (len_bool == -1)
			return (ft_freedom(readed, buffer, NULL));
		readed[len_bool] = '\0';
		if (readed[0] == '\0')
		{
			ft_freedom(readed, NULL, NULL);
			return (buffer);
		}
		buffer = ft_strjoin(buffer, readed);
		if (!buffer)
			return (ft_freedom(readed, buffer, NULL));
	}
	ft_freedom(readed, NULL, NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;
	int			line_len;
	int			buffer_len;

	i = 0;
	if (!fd || !BUFFER_SIZE)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(1);
	if (!buffer)
		return (ft_freedom(NULL, buffer, NULL));
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (ft_freedom(NULL, buffer, NULL));
	buffer_len = ft_str_to_delimiter(buffer, '\0');
	line = ft_substr(buffer, 0, ft_str_to_delimiter(buffer, '\n'));
	if (!line)
		return (ft_freedom (NULL, NULL, line));
	line_len = ft_str_to_delimiter(line, '\0');
	buffer = ft_memcpy(buffer, buffer + line_len, buffer_len - line_len);
	if (!buffer)
		return (ft_freedom(NULL, buffer, NULL));
	return (line);
}  

int	main(void)
{
	int		txt;
	char	*strget;

	txt = open("/Users/fsantill/provisorios/Getnextline/Pruebas.txt", O_RDONLY);
	if (txt == -1)
		printf("\nError al intentar abrir el archivo para lectura\n");
	strget = get_next_line(txt);
	printf("\nLine: %s\n", strget);
	while (strget)
	{
		strget = get_next_line(txt);
		printf("\nLine: %s\n", strget);
	}
	close(txt);
	return (0);
}

// tienes que resetear buffer con el valor deseado cuidado con los allocs
// strlen de line y sumarle al puntero de buffer
// strchr de line en buffer y que buffer sea igual