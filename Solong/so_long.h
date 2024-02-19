/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:15 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/19 13:13:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

typedef struct t_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

typedef struct t_map
{
	char			**content;
}					t_map;

void	leaks(void);
int		ft_error(int e);
void	*ft_arr_free(char **arr);
int		map_is_rectangular(t_map **mapa);
char	**parsing_map_and_add(int argc, char **argv, t_map **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif

/*
typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; 	// Map pointer (contains map details
						// preferably kept on the stack)
}	t_data;
*/