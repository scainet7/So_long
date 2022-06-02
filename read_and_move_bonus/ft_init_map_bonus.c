/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:41:11 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:41:12 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_pars_walls(t_game *game, int y_num, int x_num)
{
	if (y_num == 0 && x_num == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall1.ptr,
			(IMG * x_num), (IMG * y_num));
	else if (y_num == 0 && x_num == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->wall2.ptr,
			(IMG * x_num), (IMG * y_num));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr,
			(IMG * x_num), (IMG * y_num));
}

static void	ft_player_position(t_game *game, int y_num, int x_num)
{
	game->player.x = (x_num * IMG);
	game->player.y = (y_num * IMG);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		(IMG * x_num), (IMG * y_num));
}

static void	ft_check_collection_exit(t_game *game, int y_num, int x_num)
{
	if (!game->lines.collection)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_o.ptr,
			(IMG * x_num), (IMG * y_num));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit_c.ptr,
			(IMG * x_num), (IMG * y_num));
}

static void	ft_parse_line(t_game *game, int y_num, int x_num)
{
	static int	count;

	if (game->lines.map[y_num][x_num] == '1')
		ft_pars_walls(game, y_num, x_num);
	else if (game->lines.map[y_num][x_num] == 'P' && !count)
	{
		ft_player_position(game, y_num, x_num);
		count++;
	}
	else if (game->lines.map[y_num][x_num] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->key.ptr,
			(IMG * x_num), (IMG * y_num));
	else if (game->lines.map[y_num][x_num] == 'Y')
	{
	}
	else if (game->lines.map[y_num][x_num] == 'E')
		ft_check_collection_exit(game, y_num, x_num);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * x_num), (IMG * y_num));
}

void	ft_init_map(t_game *game)
{
	int	y_num;
	int	x_num;

	y_num = 0;
	while (game->lines.map[y_num])
	{
		x_num = 0;
		while (game->lines.map[y_num][x_num])
		{
			ft_parse_line(game, y_num, x_num);
			x_num++;
		}
		y_num++;
	}
	ft_print_moves(game);
}
