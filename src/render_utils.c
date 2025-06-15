/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:16 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:17 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		mlx_image_to_window(game->mlx, game->wall_img, j * 32, i * 32);
	}
	else if (game->map[i][j] == 'P')
	{
		mlx_image_to_window(game->mlx, game->player_img, j * 32, i * 32);
	}
	else if (game->map[i][j] == 'C')
	{
		mlx_image_to_window(game->mlx, game->coin_img, j * 32, i * 32);
	}
	else if (game->map[i][j] == 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_img, j * 32, i * 32);
	}
}

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			mlx_image_to_window(game->mlx, game->background_img, j * 32, i
				* 32);
			j++;
		}
		i++;
	}
}
