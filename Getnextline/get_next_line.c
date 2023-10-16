/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/16 15:37:57 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char *readed;
	int	f;

	readed = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!readed)
		return (NULL);
	f = read(fd, readed, BUFFER_SIZE);
	if (f == -1)
	{
		free (readed);
		return (NULL);
	}
	readed[f] = '\0';
	return (readed);
}

int		ft_countlines(char *buf)
{
	int	j;

	j = 0;
	while (buf[j] != '\n' || buf[j] != '\n')
		j++;
	return (j);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char *line;
	int	i;

	i = 0;
	buffer = ft_read(fd);
	while (!ft_strchr(buffer, '\n') || !ft_strchr(buffer, '\0'))
	{
		buffer = ft_strjoin(buffer, ft_read(fd));
	}
	line = ft_substr(buffer, 0, ft_countlines(buffer));


	ft_memcpy(buffer, buffer + ft_strlen(line), ft_strlen(buffer) - ft_strlen(line));
	return (line);
}

int	main()
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