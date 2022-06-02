/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:21:59 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 21:22:02 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_enemy_line(t_game *game)
{
	static int	y_num;
	static int	x_num;

	if (y_num > game->lines.y_len)
		y_num = 0;
	while (game->lines.map[y_num])
	{
		if (x_num > game->lines.x_len)
			x_num = 0;
		while (game->lines.map[y_num][x_num])
		{
			if (game->lines.map[y_num][x_num] == 'Y')
			{
				x_num++;
				return (y_num);
			}
			x_num++;
		}
		y_num++;
	}
	return (-1);
}

static int	ft_enemy_column(t_game *game)
{
	static int	y_num;
	static int	x_num;

	if (y_num > game->lines.y_len)
		y_num = 0;
	while (game->lines.map[y_num])
	{
		if (x_num > game->lines.x_len)
			x_num = 0;
		while (game->lines.map[y_num][x_num])
		{
			if (game->lines.map[y_num][x_num] == 'Y')
			{
				x_num++;
				return (x_num - 1);
			}
			x_num++;
		}
		y_num++;
	}
	return (-1);
}

static void	ft_animate_enemy_left(t_game *game)
{
	static int	i;

	i++;
	if (i == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p5.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 4)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p6.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p7.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 8)
	{
		if (!((game->lines.enemy + 1) % 2 == 0))
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy.p8.ptr, (ft_enemy_column(game) * IMG),
				(ft_enemy_line(game) * IMG));
		i = 0;
	}
}

static void	ft_animate_enemy_right(t_game *game)
{
	static int	i;

	i++;
	if (i == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 4)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p1.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.p2.ptr, (ft_enemy_column(game) * IMG),
			(ft_enemy_line(game) * IMG));
	else if (i == 8)
	{
		if (!((game->lines.enemy + 1) % 2 == 0))
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy.p3.ptr, (ft_enemy_column(game) * IMG),
				(ft_enemy_line(game) * IMG));
		i = 0;
	}
}

int	ft_animate_enemy(t_game *game)
{
	int		key;

	key = game->key_enemy;
	if (key == 10)
		ft_animate_enemy_left(game);
	else if (key == 0)
		ft_animate_enemy_right(game);
	else
		return (1);
	return (0);
}
