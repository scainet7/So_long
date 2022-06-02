/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:47:15 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 16:47:18 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	ft_x(t_game *game)
{
	int	x_num;
	int	y_num;

	x_num = 0;
	y_num = game->lines.y_len;
	while (game->lines.map[0][x_num])
	{
		if (game->lines.map[0][x_num] != '1')
			ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
		x_num++;
	}
	x_num = 0;
	while (game->lines.map[y_num][x_num])
	{
		if (game->lines.map[y_num][x_num] != '1')
			ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
		x_num++;
	}
}

static	void	ft_y(t_game *game)
{
	int	x_num;
	int	y_num;

	y_num = 0;
	x_num = game->lines.x_len;
	while (game->lines.map[y_num])
	{
		if (game->lines.map[y_num][0] != '1')
			ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
		y_num++;
	}
	y_num = 0;
	while (game->lines.map[y_num])
	{
		if (game->lines.map[y_num][x_num] != '1')
			ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
		y_num++;
	}
}

void	ft_check_map_format(t_game *game)
{
	ft_x(game);
	ft_y(game);
}
