/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:47 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:48 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_new_position(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
	{
		return ;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles > 0)
		{
			return ;
		}
		show_message_simple("Congratulations, you completed the game!");
		mlx_terminate(game->mlx);
		exit(0);
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
	}
	game->map[game->s_player_pos.y][game->s_player_pos.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->s_player_pos.x = new_x;
	game->s_player_pos.y = new_y;
	render_map(game);
	show_message_with_coords("Moved to: ", new_x, new_y);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->s_player_pos.x + dx;
	new_y = game->s_player_pos.y + dy;
	if (game->map[new_y][new_x] != '1' && (game->map[new_y][new_x] != 'E'
			|| game->collectibles == 0))
	{
		handle_new_position(game, new_x, new_y);
		game->moves++;
		show_message_with_moves("move sucessful, total move ", game->moves);
	}
	else if (game->map[new_y][new_x] == 'E' && game->collectibles > 0)
	{
		show_message_simple("Collect all the items before leaving.");
	}
}

void	start_game(t_game *game)
{
	render_map(game);
	mlx_key_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
}
