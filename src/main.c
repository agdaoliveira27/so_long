/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:24 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:36:58 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		show_message_simple("Error\nUsage: ./so_long <map_file>");
		return (1);
	}
	get_map_dimensions(argv[1], &game.width, &game.height);
	if (!init_game(&game, argv[1]))
	{
		show_message_simple("Error\nFailed to initialize the game");
		return (1);
	}
	if (!validate_map(&game))
	{
		show_message_simple("Error\nInvalid map");
		return (1);
	}
	init_graphics(&game);
	start_game(&game);
	return (0);
}
