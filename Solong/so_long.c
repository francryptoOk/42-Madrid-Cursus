/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/06 15:24:13 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_click_to_close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit (0);
	return (0);
}

void	ft_assign_images_in_map(t_win win, t_map *map)
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
				p = mlx_xpm_file_to_image(win.mlx, TXT1, &win.dim, &win.dim);
			else if (map->map_orig[y][x] == '0')
				p = mlx_xpm_file_to_image(win.mlx, TXT0, &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'C')
				p = mlx_xpm_file_to_image(win.mlx, TXTC, &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'E')
				p = mlx_xpm_file_to_image(win.mlx, TXTE, &win.dim, &win.dim);
			else if (map->map_orig[y][x] == 'P')
				p = mlx_xpm_file_to_image(win.mlx, TXTP, &win.dim, &win.dim);
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
		if (ft_verify_extension(argv) != 0)
			return (1);
		maps = ft_args_to_maps(argv, &maps);
		if (ft_map_parsing(&maps) == 1)
			return (1);
		win.map = &maps;
		win.mlx = mlx_init();
		if (!win.mlx)
			exit (ft_error_msg("Error\n\t• Mlx pointer doesn't exist"));
		win.mlx_win = mlx_new_window(win.mlx, ft_len_of_x(&maps) * 48, \
		ft_len_of_y(&maps) * 48, "Boca Juniors Training Game");
		if (!win.mlx_win)
			exit (ft_error_msg("Error\n\t• Mlx win doesn't exist"));
		ft_collectibles_count_and_player_first_y_x_position(&maps);
		ft_assign_images_in_map(win, &maps);
		mlx_key_hook(win.mlx_win, ft_key_bind, &win);
		mlx_hook(win.mlx_win, 17, 0, ft_click_to_close_window, &win);
		return (mlx_loop(win.mlx), free(win.mlx), 0);
	}
	exit (ft_error_msg("Error\n\t• Invalid arguments"));
}
