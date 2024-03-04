/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/04 14:21:48 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	Errors of 'map_is_closed' are inside the function depending the open side
//	For bonus:
//	else if (map_search_and_count(map, "R") != 1)
//		exit (error_msg("Error\n\t• Map Rival problem\n"));

int	map_parsing(t_map *map)
{
	if (map_is_rectangular(map) == 1)
		exit (error_msg("Error\n\t• Not a rectangular map"));
	else if (map_is_closed(map) == 1)
		exit (1);
	else if (map_search_and_count(map, "E") != 1)
		exit (error_msg("Error\n\t• Map Exit problem\n"));
	else if (map_search_and_count(map, "P") != 1)
		exit (error_msg("Error\n\t• Map Player problem\n"));
	else if (map_search_and_count(map, "C") <= 0)
		exit (error_msg("Error\n\t• Map Collectibles problem\n"));
	else if (map_flood(1, 1, map) == 1)
		exit (error_msg("Error\n\t• Cannot take collectibles or exit\n"));
	return (0);
}

int	map_is_rectangular(t_map *map)
{
	int	columns;
	int	lines;
	int	i;

	columns = len_of_x(map);
	lines = len_of_y(map);
	ft_printf("\nLines: %i\nColumns: %i\n", columns, lines);
	i = 0;
	while (map->map_copy[i] && i < lines)
	{
		ft_printf("MAP LINE: %s\n", map->map_copy[i]);
		if (ft_strlen(map->map_copy[i]) != columns)
			return (1);
		i++;
	}
	return (ft_printf("\n--- Map Rectangular: OK ---\n"), 0);
}

// ft_printf("Diferencia: %i // %i\n", ft_strlen(map->map_copy[i]), columns)

int	map_is_closed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map->map_copy[y][x] && map->map_copy[y][x] == '1')
		x++;
	if (map->map_copy[y][x] != '\0')
		return (error_msg("Error\n\t• Map is open on top"), 1);
	while (++y < (len_of_y(map) - 1))
	{
		if (map->map_copy[y][0] != '1')
			return (error_msg("Error\n\t• Map is open on left"), 1);
		if (map->map_copy[y][len_of_x(map) - 1] != '1')
			return (error_msg("Error\n\t• Map is open on right"), 1);
	}
	x = 0;
	while (map->map_copy[y][x] && map->map_copy[y][x] == '1')
		x++;
	if (map->map_copy[y][x] != '\0')
		return (error_msg("Error\n\t• Map is open on bottom"), 1);
	return (ft_printf("\n--- Map Closed: OK---\n"), 0);
}

int	map_search_and_count(t_map *map, char *str)
{
	int	columns;
	int	x;
	int	lines;
	int	y;
	int	count;

	columns = len_of_x(map);
	lines = len_of_y(map);
	y = 0;
	count = 0;
	while (y < lines)
	{
		x = 0;
		while (x < columns)
		{
			if (map->map_copy[y][x] == (*str))
				count++;
			x++;
		}
		y++;
	}
	ft_printf("\n--- Map amount of %s: %i ---\n", str, count);
	return (count);
}

int	map_flood(int y, int x, t_map *map)
{
	if (x < len_of_x(map) && x > 0 && \
		y < len_of_y(map) && y > 0)
	{
		if (map->map_copy[y][x] == 'E')
			map->map_copy[y][x] = '1';
		map->map_copy[y][x] = '1';
		if (map->map_copy[y - 1][x] != '1')
			map_flood(y - 1, x, map);
		if (map->map_copy[y][x + 1] != '1')
			map_flood(y, x + 1, map);
		if (map->map_copy[y + 1][x] != '1')
			map_flood(y + 1, x, map);
		if (map->map_copy[y][x - 1] != '1')
			map_flood(y, x - 1, map);
		ft_printf("MAP COPY LINE %i: %s\n\n", y, map->map_copy[y]);
	}
	if (map_search_and_count(map, "0") != 0 || \
		map_search_and_count(map, "E") != 0)
		return (1);
	return (0);
}

/*
if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;
*/