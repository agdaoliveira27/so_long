/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:21 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:21 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	load_map(t_game *game, char *map_file)
{
	int	fd;
	int	i;
	int	j;

	fd = open(map_file, O_RDONLY);
	check_error(fd == -1, "Error opening the map file");
	game->map = malloc(sizeof(char *) * game->height);
	check_error(!game->map, "Memory allocation error");
	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
		{
			check_error(!game->map[i], "Error reading map");
			free_map(game);
		}
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
			j++;
		game->map[i][j] = '\0';
		i++;
	}
	close(fd);
}

void	get_map_dimensions(char *map_file, int *width, int *height)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	check_error(fd == -1, "Error opening the map file");
	*height = 0;
	line = get_next_line(fd);
	if (line)
	{
		*width = 0;
		while (line[*width] && line[*width] != '\n')
			(*width)++;
		free(line);
		(*height)++;
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		(*height)++;
		line = get_next_line(fd);
	}
	close(fd);
}
