/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:47 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:38:50 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_check_exit(t_game *game, int move)
{
	if (move == left && game->lines.map[(game->player.y / IMG)][(
			(game->player.x / IMG) - 1)] == 'E' && game->lines.collection > 0)
		return (1);
	else if (move == right && game->lines.map[(game->player.y / IMG)][(
			(game->player.x / IMG) + 1)] == 'E' && game->lines.collection > 0)
		return (1);
	else if (move == up && game->lines.map[((game->player.y / IMG) - 1)][(
			game->player.x / IMG)] == 'E' && game->lines.collection > 0)
		return (1);
	else if (move == down && game->lines.map[((game->player.y / IMG) + 1)][(
			game->player.x / IMG)] == 'E' && game->lines.collection > 0)
		return (1);
	return (0);
}

static int	ft_mid_walls(t_game *game, int move)
{
	if (move == left && (game->lines.map[(game->player.y / IMG)][
			((game->player.x / IMG) - 1)] == '1' || ft_check_exit(game, left)))
		return (1);
	else if (move == right && (game->lines.map[(game->player.y / IMG)][
			((game->player.x / IMG) + 1)] == '1' || ft_check_exit(game, right)))
		return (1);
	else if (move == up && (game->lines.map[((game->player.y / IMG) - 1)][
			(game->player.x / IMG)] == '1' || ft_check_exit(game, up)))
		return (1);
	else if (move == down && (game->lines.map[((game->player.y / IMG) + 1)][
			(game->player.x / IMG)] == '1' || ft_check_exit(game, down)))
		return (1);
	return (0);
}

int	ft_move_player(t_game *game, int move)
{
	static int	movement;

	if (move == left && !ft_mid_walls(game, left) && !(game->player.x <= IMG))
	{
		game->player.x -= IMG;
		return (++movement);
	}
	else if (move == right && !ft_mid_walls(game, right) && !(game->player.x
			>= (game->lines.x_len * IMG) - IMG))
	{
		game->player.x += IMG;
		return (++movement);
	}
	else if (move == up && !ft_mid_walls(game, up) && !(game->player.y <= IMG))
	{
		game->player.y -= IMG;
		return (++movement);
	}
	else if (move == down && !ft_mid_walls(game, down) && !(game->player.y
			>= (game->lines.y_len * IMG) - IMG))
	{
		game->player.y += IMG;
		return (++movement);
	}
	return (0);
}
