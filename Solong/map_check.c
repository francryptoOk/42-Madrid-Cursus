/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/26 15:12:25 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(t_map *map)
{
	if (map_is_rectangular(map) == 1)
		return (1);
	if (map_is_closed(map) == 1)
		return (1);
	return (0);
}

//	inundar de 1 el mapa para verificar debajo si:
//	* se pueden juntar coleccionables
//	* se puede llegar al final
//	* hay salida valida

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
			return (ft_error_msg("Error: Not a rectangular map"), 1);
		i++;
	}
	return (0);
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
		return (ft_error_msg("Error: Map is open on top"), 1);
	while (++y < lines - 1)
	{
		if (map->map_copy[y][0] != '1' || map->map_copy[y][columns - 1] != '1')
			return (ft_error_msg("Error: Map is open on left or right"), 1);
		y++;
	}
	x = 0;
	while (map->map_copy[y][x] && map->map_copy[y][x] == '1')
		x++;
	if (map->map_copy[y][x] != '\0')
		return (ft_error_msg("Error: Map is open on bottom"), 1);
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