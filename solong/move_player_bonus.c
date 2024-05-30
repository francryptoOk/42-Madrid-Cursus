/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:50:57 by fsantill          #+#    #+#             */
/*   Updated: 2024/05/30 15:15:21 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_steps(t_win *win)
{
	win->map->steps++;
	ft_printf("Steps: %i\n", win->map->steps);
}

void	ft_move_up(t_win *win)
{
	int	x;
	int	y;

	x = win->map->player_x;
	y = win->map->player_y;
	if ((win->map->map_orig[y - 1][x] != '1') && \
		(win->map->map_orig[y - 1][x] != 'E') && \
		(win->map->map_orig[y - 1][x] != 'R'))
	{
		if (win->map->map_orig[y - 1][x] == 'C')
			win->map->collectibles--;
		ft_add_steps(win);
		win->map->map_orig[y][x] = '0';
		win->map->map_orig[y - 1][x] = 'P';
//		mlx_clear_window(win->mlx, win->mlx_win);
		ft_assign_images_in_map(*win, win->map);
		win->map->player_y = y - 1;
	}
	else if (win->map->map_orig[y - 1][x] == 'R' || \
	((win->map->map_orig[y - 1][x] == 'E') && (win->map->collectibles == 0)))
	{
		win->map->steps++;
		ft_printf("Steps: %i\n", win->map->steps);
		exit(0);
	}
}

void	ft_move_down(t_win *win)
{
	int	x;
	int	y;

	x = win->map->player_x;
	y = win->map->player_y;
	if ((win->map->map_orig[y + 1][x] != '1') && \
		(win->map->map_orig[y + 1][x] != 'E') && \
		(win->map->map_orig[y + 1][x] != 'R'))
	{
		if (win->map->map_orig[y + 1][x] == 'C')
			win->map->collectibles--;
		ft_add_steps(win);
		win->map->map_orig[y][x] = '0';
		win->map->map_orig[y + 1][x] = 'P';
//		mlx_clear_window(win->mlx, win->mlx_win);
		ft_assign_images_in_map(*win, win->map);
		win->map->player_y = y + 1;
	}
	else if (win->map->map_orig[y + 1][x] == 'R' || \
	((win->map->map_orig[y + 1][x] == 'E') && (win->map->collectibles == 0)))
	{
		win->map->steps++;
		ft_printf("Steps: %i\n", win->map->steps);
		exit(0);
	}
}

void	ft_move_left(t_win *win)
{
	int	x;
	int	y;

	x = win->map->player_x;
	y = win->map->player_y;
	if ((win->map->map_orig[y][x - 1] != '1') && \
		(win->map->map_orig[y][x - 1] != 'E') && \
		(win->map->map_orig[y][x - 1] != 'R'))
	{
		if (win->map->map_orig[y][x - 1] == 'C')
			win->map->collectibles--;
		ft_add_steps(win);
		win->map->map_orig[y][x] = '0';
		win->map->map_orig[y][x - 1] = 'P';
//		mlx_clear_window(win->mlx, win->mlx_win);
		ft_assign_images_in_map(*win, win->map);
		win->map->player_x = x - 1;
	}
	else if (win->map->map_orig[y][x - 1] == 'R' || \
	((win->map->map_orig[y][x - 1] == 'E') && (win->map->collectibles == 0)))
	{
		win->map->steps++;
		ft_printf("Steps: %i\n", win->map->steps);
		exit(0);
	}
}

void	ft_move_right(t_win *win)
{
	int	x;
	int	y;

	x = win->map->player_x;
	y = win->map->player_y;
	if ((win->map->map_orig[y][x + 1] != '1') && \
		(win->map->map_orig[y][x + 1] != 'E') && \
		(win->map->map_orig[y][x + 1] != 'R'))
	{
		if (win->map->map_orig[y][x + 1] == 'C')
			win->map->collectibles--;
		ft_add_steps(win);
		win->map->map_orig[y][x] = '0';
		win->map->map_orig[y][x + 1] = 'P';
//		mlx_clear_window(win->mlx, win->mlx_win);
		ft_assign_images_in_map(*win, win->map);
		win->map->player_x = x + 1;
	}
	else if (win->map->map_orig[y][x + 1] == 'R' || \
	((win->map->map_orig[y][x + 1] == 'E') && (win->map->collectibles == 0)))
	{
		win->map->steps++;
		ft_printf("Steps: %i\n", win->map->steps);
		exit(0);
	}
}
