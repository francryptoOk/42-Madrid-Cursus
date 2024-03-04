/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:07:31 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/04 14:21:22 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_extension(char **argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_msg("Error\n\t• Map doesn't exist or cannot be open"), 1);
	while (argv[1][i])
		i++;
	i--;
	if (argv[1][i] == 'r' && argv[1][--i] == 'e' && \
		argv[1][--i] == 'b' && argv[1][--i] == '.')
		;
	else
		return (error_msg("Error\n\t• Not '.ber' extension"), 1);
	return (0);
}

t_map	args_to_maps(char **argv, t_map *map)
{
	int		fd;
	char	*str_mem;
	ssize_t	read_end;
	char	**result_orig;
	char	**result_copy;

	fd = open(argv[1], O_RDONLY);
	str_mem = (char *)malloc(BUFFER_SIZE * sizeof(char *));
	read_end = read(fd, str_mem, BUFFER_SIZE);
	str_mem[read_end] = '\0';
	if (chr_of_invalid_void(str_mem, '\n'))
		exit (error_msg("Error\n\t• Map with invalid void lines"));
	result_orig = ft_split(str_mem, '\n');
	result_copy = ft_split(str_mem, '\n');
	if (result_orig == NULL || result_copy == NULL)
		exit (error_msg("Error\n\t• Split failed"));
	map->map_orig = result_orig;
	map->map_copy = result_copy;
	free(str_mem);
	str_mem = NULL;
	return ((*map));
}

int	chr_of_invalid_void(char *str, char voidline)
{
	int	i;

	i = 0;
	if (str[i] == voidline)
		return (1);
	while (str[i])
	{
		if (str[i] == voidline && str[i - 1] == voidline)
			return (1);
		i++;
	}
	return (0);
}

int	len_of_x(t_map *map)
{
	char	*str;
	int		len;

	str = map->map_copy[0];
	len = ft_strlen(str);
	return (len);
}

int	len_of_y(t_map *map)
{
	int	len;

	len = 0;
	while (map->map_copy[len])
		len++;
	return (len);
}
