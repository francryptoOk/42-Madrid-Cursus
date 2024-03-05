/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:22:29 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:52 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//buscar al jugador y guardar X e Y del jugador en el mapa
//si pulso arriba, ver que hay, si es 1 no pasa nada, si es 0 tengo que
//printear la imagen del jugador
//y donde esta el jugador tengo que printear 0, si es una coin lo mismo
//pero una variable collectable
//si es exit ver si alcanzò todos los colectables

int	key_bind(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(win);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(win);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(win);
	else if (keycode == 0 || keycode == 123)
		ft_move_left(win);
	return (0);
}

void	collectibles_count_and_player_first_y_x_position(t_map *map)
{
	int	columns;
	int	x;
	int	lines;
	int	y;
	int	count;

	map->collectibles = map_orig_search_and_count(map, "C");
	ft_printf("Collectibles: %i\n\n", map->collectibles);
	columns = len_of_x(map);
	lines = len_of_y(map);
	y = -1;
	count = 0;
	while (++y < lines)
	{
		x = -1;
		while (++x < columns)
		{
			if (map->map_orig[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
				break ;
			}
		}
	}
}

// ft_printf("\nP starting x: %i\n", x);
// ft_printf("\nP starting y: %i\n", y);

int	map_orig_search_and_count(t_map *map, char *str)
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
			if (map->map_orig[y][x] == (*str))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

//	int i = -1;
//	int j = 0;
//	while (map->map_orig[j][++i])
//	{
//		ft_printf("MAP LINE: %s\n", map->map_orig[i]);
//		j++;
//	}
