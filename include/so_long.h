/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:30:36 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:36:40 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flood_fill_data
{
	char		**grid;
	int			max_y;
	int			max_x;
}				t_flood_fill_data;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*win;
	char		**map;
	int			width;
	int			height;
	int			moves;
	mlx_image_t	*player_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*coin_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*background_img;
	int			img_width;
	int			img_height;
	int			collectibles;
	struct
	{
		int		x;
		int		y;
	} s_player_pos;
}				t_game;

int				init_game(t_game *game, char *map_file);
void			start_game(t_game *game);
void			handle_input(struct mlx_key_data keydata, void *param);
void			render_map(t_game *game);
void			init_graphics(t_game *game);
void			get_map_dimensions(char *map_file, int *width, int *height);
void			load_map(t_game *game, char *map_file);
bool			validate_map(t_game *game);
void			move_player(t_game *game, int dx, int dy);
void			show_message_simple(const char *message);
void			show_message_with_coords(const char *message, int x, int y);
void			show_message_with_moves(const char *message, int moves);
void			check_error(int condition, const char *error_message);
void			check_conditions(int condition, const char *error_message,
					void (*action)(void));
mlx_texture_t	*load_texture(const char *file);
void			create_image(t_game *game, mlx_texture_t *texture,
					mlx_image_t **image);
int				validate_path(t_game *game);
void			perform_flood_fill(t_game *game);
bool			validate_and_restore(t_game *game);
void			draw_elements(t_game *game, int i, int j);
void			draw_background(t_game *game);

#endif
