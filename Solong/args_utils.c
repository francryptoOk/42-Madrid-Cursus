/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:07:31 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/21 15:12:04 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verifying_extension(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	i--;
	if (argv[1][i] == 'r' && argv[1][--i] == 'e' && \
		argv[1][--i] == 'b' && argv[1][--i] == '.')
		;
	else
		ft_error_msg("Extension error", 1);
	return (0);
}

void	args_to_maps(char **argv, t_map *map)
{
	int		fd;
	char	*str_mem;
	ssize_t	read_end;
	char	**result_orig;
	char	**result_copy;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error_msg("Open error", 1);
	str_mem = (char *)malloc(BUFFER_SIZE * sizeof(char *));
	read_end = read(fd, str_mem, BUFFER_SIZE);
	str_mem[read_end] = '\0';
	result_orig = ft_split(str_mem, '\n');
	result_copy = ft_split(str_mem, '\n');
	if (result_orig == NULL || result_copy == NULL)
		ft_error_msg("Split error", 1);
	map->map_orig = result_orig;
	map->map_copy = result_copy;
	free(str_mem);
	str_mem = NULL;
}

int	len_of_x(t_map *map)
{
	char	*str;
	int		len;

	str = *map->map_copy;
	len = ft_strlen(str);
	return (ft_printf("Len X: %i\n", len), len);
}

int	len_of_y(t_map *map)
{
	int	len;

	len = 0;
	while (map->map_copy[len])
		len++;
	return (ft_printf("Len Y: %i\n", len), len);
}
