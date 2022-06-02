/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:19:18 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 22:19:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_move_left(t_game *game, int h, int w)
{
	if (game->lines.map[h][w] == 'Y' && game->lines.map[h][w - 1] == '0')
	{
		game->lines.map[h][w] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->lines.map[h][w - 1] = 'Y';
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p5.ptr,
			(IMG * (w - 1)), (IMG * h));
		ft_exit_map(game);
		game->key_enemy = 10;
	}
	else if (game->lines.map[h][w] == 'Y' && game->lines.map[h][w - 1] != '0')
	{
		game->lines.map[h][w] = 'Y';
		game->key_enemy = 0;
	}
}

static void	ft_move_right(t_game *game, int h, int w)
{
	if (game->lines.map[h][w] == 'Y' && game->lines.map[h][w + 1] == '0')
	{
		game->lines.map[h][w] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->lines.map[h][w + 1] = 'Y';
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p.ptr,
			(IMG * (w + 1)), (IMG * h));
		ft_exit_map(game);
		game->key_enemy = 0;
	}
	else if (game->lines.map[h][w] == 'Y' && game->lines.map[h][w + 1] != '0')
	{
		game->lines.map[h][w] = 'Y';
		game->key_enemy = 10;
	}
}

static void	ft_move_left_right(t_game *game, int h, int w)
{
	int	key;

	key = game->key_enemy;
	if (key == 0)
		ft_move_right(game, h, w);
	else if (key == 10)
		ft_move_left(game, h, w);
}

static void	ft_check_position(t_game *game)
{
	static int	h;
	static int	w;

	if (h > game->lines.y_len)
		h = 0;
	while (game->lines.map[h])
	{
		if (w > game->lines.x_len)
			w = 0;
		while (game->lines.map[h][w])
		{
			if (game->lines.map[h][w] == 'Y')
			{
				ft_move_left_right(game, h, w);
				w++;
			}
			w++;
		}
		h++;
	}
	return ;
}

int	ft_move_enemy(t_game *game)
{
	static int	i;

	i++;
	if (i == 20)
	{
		ft_check_position(game);
		i = 0;
	}
	ft_animate_enemy(game);
	return (0);
}
