/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/14 15:24:56 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void drawing()
{

}*/

char	**parsing_map_and_add(int argc, char **argv, t_map **map)
{
	int		fd;
	char	**map_aux;
	int		y;
	int		x;

	map_aux = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			return (perror("Error opening file\n"), NULL);
		map_aux[1] = "";
		y = 0;
		x = 0;
		while (map_aux[y])
		{
			while (map_aux[y][x])
			{
				map_aux[y][x] = *get_next_line(fd);
				(*map)->map = map_aux;
				if (map_aux)
					printf("Map Line:\n%s\n", map_aux[y]);
				x++;
			}
			y++;
		}
	}
	free(map_aux);
	return (printf("\n"), map_aux);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(/*int argc, char **argv*/)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
//	t_map	*startmap;

//	mlx_win = NULL;
//	mlx = NULL;
//	startmap->map = parsing_map_and_add(argc, argv, &startmap);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Game");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

//	mlx_key_hook(); bind keys for the game in the keyboard
//	mlx_loop_hook(drawing, .....); add a loop in the game
//	mlx_xpm_file_to_image(); transform xpm to image
//	mlx_put_image_to_window(); put the image in the window

//	map [y][x]
//	1111
//	1001
//	1111