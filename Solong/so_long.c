/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/21 14:52:40 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_window	startwindow;
	t_map		startmaps;
	void		*mlx_ptr;
	void		*mlx_win;

	if (argc == 2)
	{
		verifying_extension(argv);
		args_to_maps(argv, &startmaps);
		map_parsing(&startmaps);
		startwindow.map = &startmaps;
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			ft_error_msg("Mlx error", 1);
		mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Game");
		if (!mlx_win)
		{
			free(mlx_ptr);
			ft_error_msg("Mlx window error", 1);
		}
//		img.img = mlx_new_image(mlx_ptr, 640, 480);
//		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
//		&img.line_length, &img.endian);
//		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//		mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
//		mlx_loop(mlx_ptr);
//		free(mlx_ptr);
		return (0);
	}
	ft_error_msg("Arguments error", 1);
}

//	mlx_key_hook(); bind keys for the game in the keyboard
//	mlx_loop_hook(drawing, .....); add a loop in the game
//	mlx_xpm_file_to_image(); transform xpm to image
//	mlx_put_image_to_window(); put the image in the window

//	map [y][x]
//	1111
//	1001
//	1111