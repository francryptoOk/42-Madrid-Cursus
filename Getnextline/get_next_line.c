/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:34:15 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/27 15:35:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*temp;
	int		len_bool;

	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (ft_freedom(&readed), ft_freedom(&buffer));
	while (!ft_strchr_mod(buffer, '\n'))
	{
		len_bool = read(fd, readed, BUFFER_SIZE);
		if (len_bool == -1)
			return (ft_freedom(&readed), ft_freedom(&buffer));
		readed[len_bool] = '\0';
		if (readed[0] == '\0')
			return (ft_freedom(&readed), buffer);
		temp = ft_strjoin_mod(buffer, readed);
		if (!temp)
			return (ft_freedom(&temp), ft_freedom(&buffer));
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
	if (buffer[i] == '\n')
		i++;
	result = (char *)malloc(ft_strlen_to_delimiter(buffer, '\0') - i + 1);
	if (!buffer || !result)
		return (ft_freedom(&buffer), ft_freedom(&result), NULL);
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
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (ft_freedom(&buffer), NULL);
		
	//Prueba
		write(1,"\n\nINITIAL BUFFER:\n", 19);
		write(1, buffer, ft_strlen_to_delimiter(buffer, '\0'));
	//Fin de prueba

	buffer_len = ft_strlen_to_delimiter(buffer, '\0');
	if (ft_strchr_mod(buffer, '\n'))
		line = ft_substr_mod(buffer, 0, \
		ft_strlen_to_delimiter(buffer, '\n') + 1);
	else
		line = ft_substr_mod(buffer, 0, \
		ft_strlen_to_delimiter(buffer, '\0') + 1);

	//Prueba
		write(1,"\n\nEXTRACTED LINE:\n", 19);
		write(1, line, ft_strlen_to_delimiter(line, '\0'));
	//Fin de prueba

	if (!line)
		return (ft_freedom(&line), ft_freedom(&buffer));
	buffer = remove_line(buffer);

	//Prueba
		write(1,"\n\nBUFFER AFTER LINE REMOVE:\n", 29);
		write(1, buffer, ft_strlen_to_delimiter(buffer, '\0'));
	//Fin de prueba

	return (line);
}

int	main(void)
{
	int		fd;
	char	*lines;

	fd = open("Pruebas.txt", O_RDONLY);
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	printf("\n\nPRINT:\n%s", lines = get_next_line(fd));
	system("\n\nleaks -q a.out");
	return (0);
}
