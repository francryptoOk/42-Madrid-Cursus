/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:22:29 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/07 15:39:24 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_bind(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 126)
	{
		win->map->player_flag = 'W';
		ft_move_up(win);
	}
	else if (keycode == 1 || keycode == 125)
	{
		win->map->player_flag = 'S';
		ft_move_down(win);
	}
	else if (keycode == 0 || keycode == 123)
	{
		win->map->player_flag = 'A';
		ft_move_left(win);
	}
	else if (keycode == 2 || keycode == 124)
	{
		win->map->player_flag = 'D';
		ft_move_right(win);
	}
	return (0);
}

void	*ft_player_animation(t_win *win, t_map *map, void *p)
{
	if (map->player_flag == 'W')
		p = mlx_xpm_file_to_image(win->mlx, TXTPW, &win->dim, &win->dim);
	else if (map->player_flag == 'S')
		p = mlx_xpm_file_to_image(win->mlx, TXTPS, &win->dim, &win->dim);
	else if (map->player_flag == 'A')
		p = mlx_xpm_file_to_image(win->mlx, TXTPA, &win->dim, &win->dim);
	else if (map->player_flag == 'D')
		p = mlx_xpm_file_to_image(win->mlx, TXTPD, &win->dim, &win->dim);
	else
		p = mlx_xpm_file_to_image(win->mlx, TXTP, &win->dim, &win->dim);
	return (p);
}

void	ft_collectibles_count_and_player_first_y_x_position(t_map *map)
{
	int	columns;
	int	x;
	int	lines;
	int	y;
	int	count;

	map->collectibles = ft_map_orig_search_and_count(map, "C");
	ft_printf("Collectibles: %i\n\n", map->collectibles);
	columns = ft_len_of_x(map);
	lines = ft_len_of_y(map);
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

int	ft_map_orig_search_and_count(t_map *map, char *str)
{
	int	columns;
	int	x;
	int	lines;
	int	y;
	int	count;

	columns = ft_len_of_x(map);
	lines = ft_len_of_y(map);
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
