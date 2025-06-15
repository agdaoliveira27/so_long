/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:41 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 13:20:42 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_game(t_game *game, char *map_file)
{
	load_map(game, map_file);
	if (!validate_map(game))
		exit(EXIT_FAILURE);
	if (!ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
		exit(EXIT_FAILURE);
	game->mlx = mlx_init(game->width * 32, game->height * 32, "So Long", true);
	if (!game->mlx)
	{
		check_error(!game->mlx, "Error initializing MLX42");
		return (0);
	}
	game->moves = 0;
	return (1);
}
