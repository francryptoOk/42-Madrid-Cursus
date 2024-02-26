/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/26 17:31:37 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(t_map *map)
{
	if (map_is_rectangular(map) == 1)
		return (1);
	else if (map_is_closed(map) == 1)
		return (1);
	else if (map_search_and_count(map, "E") != 1)
		return (error_msg("\nError: Map Exit problem\n"), 1);
	else if (map_search_and_count(map, "P") != 1)
		return (error_msg("\nError: Map Player problem\n"), 1);
	else if (map_search_and_count(map, "C") < 1)
		return (error_msg("\nError: Map Collectibles problem\n"), 1);
	return (0);
}

// VER SI TIENE PUEDE 
//	inundar de 1 el mapa para verificar debajo si:
//	* se pueden juntar coleccionables
//	* se puede llegar al final (hay salida valida)

int	map_is_rectangular(t_map *map)
{
	int	columns;
	int	lines;
	int	i;

	columns = len_of_x(map);
	lines = len_of_y(map);
	i = 0;
	while (map->map_copy[i] && i < lines)
	{
		ft_printf("\nMAP LINE: %s\n", map->map_copy[i]);
		if (ft_strlen(map->map_copy[i]) != columns)
			return (error_msg("\nError: Not a rectangular map"), 1);
		i++;
	}
	return (ft_printf("\n--- Map Rectangular: OK ---\n\n"), 0);
}
// ft_printf("Diferencia: %i // %i\n", ft_strlen(map->map_copy[i]), columns)

int	map_is_closed(t_map *map)
{
	int	columns;
	int	x;
	int	lines;
	int	y;

	columns = len_of_x(map);
	lines = len_of_y(map);
	y = 0;
	x = 0;
	while (map->map_copy[y][x] && map->map_copy[y][x] == '1')
		x++;
	if (map->map_copy[y][x] != '\0')
		return (error_msg("\nError: Map is open on top"), 1);
	while (++y < lines - 1)
	{
		if (map->map_copy[y][0] != '1' || map->map_copy[y][columns - 1] != '1')
			return (error_msg("\nError: Map is open on left or right"), 1);
	}
	x = 0;
	while (map->map_copy[y][x] && map->map_copy[y][x] == '1')
		x++;
	if (map->map_copy[y][x] != '\0')
		return (error_msg("\nError: Map is open on bottom"), 1);
	return (ft_printf("\n--- Map Closed: OK---\n\n"), 0);
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
	ft_printf("\n--- Map amount of %s: %i ---\n\n", str, count);
	return (count);
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