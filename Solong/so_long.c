/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:21 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	For Bonus:
//			else if (map->map_orig[y][x] == 'R')
//				p = mlx_xpm_file_to_image(win.mlx, "R.xpm", &win.dim, &win.dim);

int	click_to_close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit (0);
	return (0);
}

void	assign_images_in_map(t_win win, t_map *map)
{
	int		y;
	int		x;
	void	*p;

	y = -1;
	while (map->map_orig[++y])
	{
		x = -1;
		while (map->map_orig[y][++x])
		{
			if (map->map_orig[y][x] == '1')
				p = mlx_xpm_file_to_image(win.mlx, "1.xpm", &win.dim, &win.dim);
			else if (map->map_orig[y][x] == '0')
				p = mlx_xpm_file_to_image(win.mlx, "0.xpm", &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'C')
				p = mlx_xpm_file_to_image(win.mlx, "C.xpm", &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'E')
				p = mlx_xpm_file_to_image(win.mlx, "E.xpm", &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'P')
				p = mlx_xpm_file_to_image(win.mlx, "P.xpm", &win.dim, &win.dim);
			mlx_put_image_to_window(win.mlx, win.mlx_win, p, x * 48, y * 48);
		}
	}
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_map	maps;

	if (argc == 2)
	{
		if (verify_extension(argv) != 0)
			return (1);
		maps = args_to_maps(argv, &maps);
		if (map_parsing(&maps) == 1)
			return (1);
		win.map = &maps;
		win.mlx = mlx_init();
		if (!win.mlx)
			exit (error_msg("Error\n\t• Mlx pointer doesn't exist"));
		win.mlx_win = mlx_new_window(win.mlx, len_of_x(&maps) * 48, \
		len_of_y(&maps) * 48, "Boca Juniors Training Game");
		if (!win.mlx_win)
			exit (error_msg("Error\n\t• Mlx win doesn't exist"));
		collectibles_count_and_player_first_y_x_position(&maps);
		assign_images_in_map(win, &maps);
		mlx_key_hook(win.mlx_win, key_bind, &win);
		mlx_hook(win.mlx_win, 17, 0, click_to_close_window, &win);
		return (mlx_loop(win.mlx), free(win.mlx), 0);
	}
	exit (error_msg("Error\n\t• Invalid arguments"));
}

//	mlx_loop_hook(drawing, .....); add a loop in the game
