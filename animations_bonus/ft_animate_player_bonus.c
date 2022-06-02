/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:34:05 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 21:34:08 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_animate_player_right(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p.ptr, game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p1.ptr, game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p2.ptr, game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p3.ptr, game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(60);
	i++;
	return (0);
}

static int	ft_animate_player_left(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p5.ptr, game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p6.ptr, game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p7.ptr, game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.p8.ptr, game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(60);
	i++;
	return (0);
}

int	ft_animate_player(t_game *game)
{
	static int	key;

	key = game->key_press;
	if (key == RIGHT)
	{
		game->key_press_anim = key;
		ft_animate_player_right(game);
	}
	else if (key == LEFT)
	{
		game->key_press_anim = key;
		ft_animate_player_left(game);
	}
	else if (key == UP && game->key_press_anim == LEFT)
		ft_animate_player_left(game);
	else if (key == UP && game->key_press_anim == RIGHT)
		ft_animate_player_right(game);
	else if (key == DOWN && game->key_press_anim == LEFT)
		ft_animate_player_left(game);
	else if (key == DOWN && game->key_press_anim == RIGHT)
		ft_animate_player_right(game);
	return (0);
}
