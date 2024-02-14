/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/14 14:51:26 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void drawing()
{

}*/

char	**parsing_map_and_add(int argc, char **argv, t_map **map)
{
	int		file;
	char	**map_aux = NULL;
	int		y;
	int		x;

	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
		if (!file)
			return (perror("Error opening file\n"), NULL);
		map_aux[1] = "";
		y = 0;
		x = 0;
		while (map_aux[y])
		{
			while (map_aux[y][x])
			{
				map_aux[y][x] = *get_next_line(file);
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

int	main(int argc, char **argv)
{
	void	*mlx_win;
	void	*mlx;
	t_map	*startmap;

	mlx_win = NULL;
	mlx = NULL;
	startmap->map = parsing_map_and_add(argc, argv, &startmap);
	mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Game");
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