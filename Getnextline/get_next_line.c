/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/16 17:49:26 by fsantill         ###   ########.fr       */
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

char	*ft_read(int fd)
{
	char	*readed;
	int		aux;

	readed = malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	aux = read(fd, readed, BUFFER_SIZE);
	if (aux == -1)
	{
		free (readed);
		return (NULL);
	}
	readed[aux] = '\0';
	return (readed);
}

int	ft_countlines(char *buf)
{
	int	j;

	j = 0;
	while (buf[j] != '\n')
	{
		printf("J: %i\n", j);
		j++;
	}
	return (j);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (!fd)
		return (NULL);
	buffer = ft_read(fd); //el problema es que en buffer ya puede estar el salto de linea
	while (!ft_strchr(buffer, '\n'))
	{
		buffer = ft_strjoin(buffer, ft_read(fd));
	}
	line = ft_substr(buffer, 0, ft_countlines(buffer));
	ft_memcpy(buffer, buffer + ft_strlen(line), \
	ft_strlen(buffer) - ft_strlen(line));
	return (line);
}

int	main(void)
{
	int		txt;
	char	*strget;

	txt = open("/Users/fsantill/provisorios/Getnextline/Pruebas.txt", O_RDONLY);
	strget = get_next_line(txt);
	printf("Line: %s", strget);
	while (strget)
	{
		strget = get_next_line(txt);
		printf("Line: %s", strget);
	}
	if (txt == -1)
		printf("Error de lectura");
	return (0);
}

// strlen de line y sumarle al puntero de buffer
// strchr de line en buffer y que buffer sea igual