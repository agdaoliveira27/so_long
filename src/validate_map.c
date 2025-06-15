/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:09 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:10 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	is_valid_tile(t_game *game, int i, int j, int *counts)
{
	char	tile;

	tile = game->map[i][j];
	if (tile == 'E')
		counts[0]++;
	else if (tile == 'P')
	{
		counts[1]++;
		game->s_player_pos.x = j;
		game->s_player_pos.y = i;
	}
	else if (tile == 'C')
		counts[2]++;
	else if (tile != '1' && tile != '0')
	{
		show_message_simple("Error: invalid character in map.");
		return (0);
	}
	if ((i == 0 || i == game->height - 1 || j == 0 || j == game->width - 1)
		&& tile != '1')
	{
		show_message_simple("Error: map boundary is not a wall.");
		return (0);
	}
	return (1);
}

static bool	is_map_rectangular(t_game *game)
{
	int	line_length;
	int	i;

	i = 1;
	line_length = (int)ft_strlen(game->map[0]);
	i = 1;
	if (line_length == game->height)
	{
		show_message_simple("Error: Map cannot be square.");
		return (0);
	}
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != line_length)
		{
			show_message_simple("Error: Inconsistent row lengths.");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_counts(int *counts)
{
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
}

static bool	validate_map_tiles(t_game *game, int *counts)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (!is_valid_tile(game, i, j, counts))
				return (0);
			j++;
		}
		i++;
	}
	game->collectibles = counts[2];
	if (counts[0] == 1 && counts[1] == 1 && counts[2] > 0)
		return (1);
	return (0);
}

bool	validate_map(t_game *game)
{
	int	counts[3];

	init_counts(counts);
	if (!is_map_rectangular(game))
		return (0);
	if (validate_map_tiles(game, counts))
	{
		if (validate_path(game))
			return (1);
		show_message_simple("Erro: Inaccessible areas in map.");
	}
	else
	{
		show_message_simple("Error: Invalid map.");
	}
	return (0);
}
