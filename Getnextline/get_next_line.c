/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/19 17:56:43 by fsantill         ###   ########.fr       */
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

static char	*ft_read(int fd, char *buffer)
{
	char	*readed;
	int		aux_bool_len;

	readed = malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	aux_bool_len = 123;
	while (aux_bool_len && !ft_strchr(buffer, '\n'))
	{
		aux_bool_len = read(fd, readed, BUFFER_SIZE);
		if (aux_bool_len == -1)
		{
			free (readed);
			readed = NULL;
			return (NULL);
		}
		readed[aux_bool_len] = '\0';
		buffer = ft_strjoin(buffer, readed);
	}
	return (buffer);
}

static int	ft_countlines(char *buf)
{
	int	j;

	j = 0;
	while (buf[j] != '\n')
	{
		j++;
	}
	printf("J: %i\n", j);
	return (j);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (!fd || !BUFFER_SIZE)
		return (NULL);
	buffer = ft_read(fd, buffer);
	line = ft_substr(buffer, 0, ft_countlines(buffer));
	//tienes que resetear buffer con el valor deseado cuidado con los allocs
	//calloc?????
	buffer = ft_memcpy(buffer + ft_strlen(line), NULL, \
	ft_strlen(line));
	return (line);
}
//	buffer = ft_memcpy(buffer, buffer + ft_strlen(line),
//	ft_strlen(buffer) - ft_strlen(line));

/*int	main(void)
{
	int		txt;
	char	*strget;

	txt = open("/Users/fsantill/provisorios/Getnextline/Pruebas.txt", O_RDONLY);
	strget = get_next_line(txt);
	printf("\nLine: %s\n", strget);
	while (strget)
	{
		strget = get_next_line(txt);
		printf("\nLine: %s\n", strget);
	}
	if (txt == -1)
		printf("Error de lectura");
	return (0);
}*/

// strlen de line y sumarle al puntero de buffer
// strchr de line en buffer y que buffer sea igual