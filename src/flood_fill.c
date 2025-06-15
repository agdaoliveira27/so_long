/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:50 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:51 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_flood_fill_data *data, int y, int x)
{
	if (y < 0 || x < 0 || y >= data->max_y || x >= data->max_x)
		return ;
	if (data->grid[y][x] != 'P')
	{
		if (data->grid[y][x] == '0')
			data->grid[y][x] = 'o';
		else if (data->grid[y][x] == 'C')
			data->grid[y][x] = 'c';
		else if (data->grid[y][x] == 'E')
			data->grid[y][x] = 'e';
		else
			return ;
	}
	flood_fill(data, y + 1, x);
	flood_fill(data, y - 1, x);
	flood_fill(data, y, x + 1);
	flood_fill(data, y, x - 1);
}

void	perform_flood_fill(t_game *game)
{
	t_flood_fill_data	data;

	data.grid = game->map;
	data.max_y = game->height;
	data.max_x = game->width;
	flood_fill(&data, game->s_player_pos.y, game->s_player_pos.x);
}

bool	validate_and_restore(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'E') || (game->map[i][j] == 'C'))
				return (0);
			if (game->map[i][j] == 'o')
				game->map[i][j] = '0';
			else if (game->map[i][j] == 'c')
				game->map[i][j] = 'C';
			else if (game->map[i][j] == 'e')
				game->map[i][j] = 'E';
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_path(t_game *game)
{
	perform_flood_fill(game);
	return (validate_and_restore(game));
}
