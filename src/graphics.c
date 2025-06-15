/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:44 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:44 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_image_with_color(mlx_image_t *img, uint32_t color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			((uint32_t *)img->pixels)[y * img->width + x] = color;
			x++;
		}
		y++;
	}
}

void	init_graphics(t_game *game)
{
	create_image(game, load_texture("textures/player.png"), &game->player_img);
	create_image(game, load_texture("textures/wall.png"), &game->wall_img);
	create_image(game, load_texture("textures/coin.png"), &game->coin_img);
	create_image(game, load_texture("textures/exit.png"), &game->exit_img);
	create_image(game, load_texture("textures/background.png"),
		&game->background_img);
	render_map(game);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	draw_background(game);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_elements(game, i, j);
			j++;
		}
		i++;
	}
}

mlx_texture_t	*load_texture(const char *file)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file);
	check_error(!texture, "Error loading texture.");
	return (texture);
}

void	create_image(t_game *game, mlx_texture_t *texture, mlx_image_t **image)
{
	*image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
