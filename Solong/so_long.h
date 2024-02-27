/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/27 16:35:19 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

typedef struct s_map
{
	char	**map_orig;
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		steps;
	int		credits;
}					t_map;

typedef struct s_win
{
	void	*img;
	void	*mlx_ptr;
	void	*mlx_win;
	t_map	*map;
	int		dim;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_win;

void	leaks(void);
int		error_msg(char *msg);
void	*ft_arr_free(char **arr);
int		map_parsing(t_map *map);
int		map_is_rectangular(t_map *map);
int		map_is_closed(t_map *map);
int		map_search_and_count(t_map *map, char *str);
int		map_flood(int y, int x, t_map *map);
int		verify_extension(char **argv);
t_map	args_to_maps(char **argv, t_map *map);
int		chr_of_invalid_void(char *str, char voidline);
int		len_of_x(t_map *map);
int		len_of_y(t_map *map);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);

#endif

/*
typedef struct s_window
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; 	// Map pointer (contains map details
						// preferably kept on the stack)
}	t_window;
*/