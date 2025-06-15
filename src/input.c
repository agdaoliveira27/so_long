/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:29 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:29 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_input(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, 0, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, 0, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, -1, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, 1, 0);
}
