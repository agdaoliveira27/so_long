/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:13 by agbarbos          #+#    #+#             */
/*   Updated: 2025/01/14 09:27:14 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	show_message_simple(const char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}

void	show_message_with_coords(const char *message, int x, int y)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('(', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(y, 1);
	ft_putchar_fd(')', 1);
	ft_putchar_fd('\n', 1);
}

void	show_message_with_moves(const char *message, int moves)
{
	ft_putstr_fd(message, 1);
	ft_putnbr_fd(moves, 1);
	ft_putchar_fd('\n', 1);
}

void	check_error(int condition, const char *error_message)
{
	if (condition)
	{
		show_message_simple(error_message);
		exit(EXIT_FAILURE);
	}
}

void	check_conditions(int condition, const char *error_message,
		void (*action)(void))
{
	if (condition)
	{
		show_message_simple(error_message);
		if (action)
		{
			action();
		}
		exit(EXIT_FAILURE);
	}
}
