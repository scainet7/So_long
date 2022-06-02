/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_virification_map_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:36:12 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:36:15 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_check_filing(t_game *game, int y_num, int x_num)
{
	if (game->lines.map[y_num][x_num] == 'C')
		game->lines.collection++;
	else if (game->lines.map[y_num][x_num] == 'P')
		game->lines.person++;
	else if (game->lines.map[y_num][x_num] == 'E')
		game->lines.exit++;
	else if (game->lines.map[y_num][x_num] == '0')
		game->lines.nul++;
	else if (!(game->lines.map[y_num][x_num] == '1'))
		ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
}

static void	ft_map_filing(t_game *game)
{
	int	y_num;
	int	x_num;

	y_num = 0;
	game->lines.collection = 0;
	game->lines.person = 0;
	game->lines.exit = 0;
	game->lines.nul = 0;
	while (game->lines.map[y_num])
	{
		x_num = 0;
		while (game->lines.map[y_num][x_num])
		{
			ft_check_filing(game, y_num, x_num);
			x_num++;
		}
		y_num++;
	}
	if (!(game->lines.collection > 0 && game->lines.person == 1
			&& game->lines.exit > 0))
		ft_error_handler(game, "Error\nMAP_INVALID_FILING", map);
}

static void	ft_read_size_lines_x_y(t_game *game)
{
	int	len_line;
	int	y_num;
	int	x_num;

	y_num = 0;
	len_line = ft_strlen(game->lines.map[y_num]);
	while (game->lines.map[y_num])
	{
		x_num = 0;
		while (game->lines.map[y_num][x_num])
			x_num++;
		if (x_num != len_line)
			ft_error_handler(game, "Error\nMAP_LINES_DO_NOT_MATCH", map);
		y_num++;
	}
	y_num--;
	len_line--;
	if (y_num < 2 || y_num > 21 || len_line > 39)
		ft_error_handler(game,
			"Error\nNOT_ENOUGH_OR_MANY_LINES_FOR_THE_MAP", map);
	game->lines.y_len = y_num;
	game->lines.x_len = len_line;
}

void	ft_check_verification_map(t_game *game)
{
	ft_read_size_lines_x_y(game);
	ft_check_map_format(game);
	ft_map_filing(game);
	ft_wright_enemy(game);
}
