/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/26 17:32:32 by fsantill         ###   ########.fr       */
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
	t_window	window;
	t_map		maps;
	void		*mlx_ptr;
	void		*mlx_win;

	if (argc == 2)
	{
		if (verify_exist_extension(argv) == 1)
			return (1);
		maps = args_to_maps(argv, &maps);
		if (map_parsing(&maps) == 1)
			return (1);
		window.map = &maps;
		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			return (error_msg("Error: Mlx pointer doesn't exist"), 1);
		mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Game");
		if (!mlx_win)
		{
			free(mlx_ptr);
			return (error_msg("Error: Mlx window doesn't exist"), 1);
		}
		window.img = mlx_new_image(mlx_ptr, 640, 480);
		window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, \
		&window.line_length, &window.endian);
		my_mlx_pixel_put(&window, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx_ptr, mlx_win, window.img, 0, 0);
		mlx_loop(mlx_ptr);
		free(mlx_ptr);
		return (0);
	}
	return (error_msg("Error: Invalid arguments"), 1);
}

//	ft_printf("Llega\n");

//	mlx_key_hook(); bind keys for the game in the keyboard
//	mlx_loop_hook(drawing, .....); add a loop in the game
//	mlx_xpm_file_to_image(); transform xpm to image
//	mlx_put_image_to_window(); put the image in the window

//	map [y][x]
//	1111
//	1001
//	1111