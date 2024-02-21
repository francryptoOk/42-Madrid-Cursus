/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:25:34 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/21 15:11:40 by fsantill         ###   ########.fr       */
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

int	map_is_rectangular(t_map *map)
{
	int	x_len;
	int	y_len;

	x_len = len_of_x(map);
	y_len = len_of_y(map);
	while (map->map_copy[y_len])
	{
		ft_printf("\nMAP LINE: %s\n", map->map_copy[y_len]);
		if (ft_strlen(map->map_copy[y_len]) != x_len)
		{
			return (1);
			break ;
		}
		y_len--;
	}
	return (0);
}

int	map_is_closed(t_map *map)
{
	char	*str;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = len_of_x(map);
	y = len_of_y(map);
	str = *map->map_copy;
	while (str[i])
	{
		while (str[i] == '1')
			i++;
		if (str[i] != '1')
			return (1);
		y--;
	}
	while (y > 0)
	{
		if (str[0] == '1' && str[x] && str[x] == '1')
			y--;
		else
			return (1);
	}
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