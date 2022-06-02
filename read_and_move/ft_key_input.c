/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:19:22 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 16:19:47 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_print_moves(t_game *game)
{
	if (game->player.moves > 0)
	{
		ft_putstr_fd("\rMOVE: ", 1);
		ft_putnbr_fd(game->player.moves, 1);
	}
}

int	ft_key_input(int key, t_game *game)
{
	game->player.moves = 0;
	if (key == LEFT)
		game->player.moves = ft_move_player(game, left);
	else if (key == RIGHT)
		game->player.moves = ft_move_player(game, right);
	else if (key == UP)
		game->player.moves = ft_move_player(game, up);
	else if (key == DOWN)
		game->player.moves = ft_move_player(game, down);
	else if (key == ESC)
		ft_error_handler(game, "YOU_EXIT_GAME", clean);
	ft_print_moves(game);
	ft_collect_item(game);
	ft_exit_map(game);
	mlx_clear_window(game->mlx, game->win);
	ft_init_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}
