/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draft_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:03 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:38:05 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_enemy_draft(t_game *game)
{
	int	y;
	int	x;

	game->enemy.p.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy1R.xpm", &x, &y);
	game->enemy.p1.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy2R.xpm", &x, &y);
	game->enemy.p2.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy3R.xpm", &x, &y);
	game->enemy.p3.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy4R.xpm", &x, &y);
	game->enemy.p5.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy1L.xpm", &x, &y);
	game->enemy.p6.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy2L.xpm", &x, &y);
	game->enemy.p7.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy3L.xpm", &x, &y);
	game->enemy.p8.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/enemy4L.xpm", &x, &y);
}

static void	ft_player_draft(t_game *game)
{
	int	y;
	int	x;

	game->player.p.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player1R.xpm", &x, &y);
	game->player.p1.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player2R.xpm", &x, &y);
	game->player.p2.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player3R.xpm", &x, &y);
	game->player.p3.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player4R.xpm", &x, &y);
	game->player.p5.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player1L.xpm", &x, &y);
	game->player.p6.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player2L.xpm", &x, &y);
	game->player.p7.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player3L.xpm", &x, &y);
	game->player.p8.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player4L.xpm", &x, &y);
}

static void	ft_map_draft(t_game *game)
{
	int	y;
	int	x;

	game->wall.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/wall.xpm", &x, &y);
	game->wall1.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/wall2.xpm", &x, &y);
	game->wall2.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/wall1.xpm", &x, &y);
	game->floor.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/gress.xpm", &x, &y);
	game->exit_c.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/stone.xpm", &x, &y);
	game->exit_o.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/building.xpm", &x, &y);
	game->key.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/item.xpm", &x, &y);
}

void	ft_draft(t_game *game)
{
	ft_map_draft(game);
	ft_player_draft(game);
	ft_enemy_draft(game);
}
