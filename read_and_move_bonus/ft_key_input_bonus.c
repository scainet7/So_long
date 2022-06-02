/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:35 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:38:37 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_put_image_to_window_up_down(t_game *game, int key)
{
	if (key == UP && game->player.moves_plus == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == UP && game->player.moves_plus == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == DOWN && game->player.moves_plus == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == DOWN && game->player.moves_plus == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
}

static void	ft_put_image_to_window(t_game *game, int key)
{
	if (key == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else
		ft_put_image_to_window_up_down(game, key);
}

int	ft_key_input(int key, t_game *game)
{
	game->player.moves = 0;
	if (key == RIGHT)
	{
		game->player.moves = ft_move_player(game, right);
		game->player.moves_plus = key;
	}
	else if (key == LEFT)
	{
		game->player.moves = ft_move_player(game, left);
		game->player.moves_plus = key;
	}
	else if (key == UP)
		game->player.moves = ft_move_player(game, up);
	else if (key == DOWN)
		game->player.moves = ft_move_player(game, down);
	else if (key == ESC)
		game->key_press = key;
	else
		return (1);
	ft_collect_item(game);
	ft_exit_map(game);
	ft_init_map(game);
	ft_put_image_to_window(game, key);
	return (0);
}
