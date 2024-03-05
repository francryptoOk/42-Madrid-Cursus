/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:32 by fsantill         ###   ########.fr       */
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
	int		collectibles;
}					t_map;

typedef struct s_win
{
	void	*img;
	void	*mlx;
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
int		map_copy_search_and_count(t_map *map, char *str);
int		map_flood(int y, int x, t_map *map);
int		verify_extension(char **argv);
t_map	args_to_maps(char **argv, t_map *map);
int		chr_of_invalid_void(char *str, char voidline);
int		len_of_x(t_map *map);
int		len_of_y(t_map *map);
void	assign_images_in_map(t_win win, t_map *map);
void	collectibles_count_and_player_first_y_x_position(t_map *map);
void	data_count(t_map *map);
void	ft_move_up(t_win *win);
void	ft_move_down(t_win *win);
void	ft_move_left(t_win *win);
void	ft_move_right(t_win *win);
int		key_bind(int keycode, t_win *win);
int		map_orig_search_and_count(t_map *map, char *str);

#endif

//void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
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