/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:36:48 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:36:56 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_free_enemy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->enemy.p.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p1.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p2.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p3.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p5.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p6.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p7.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p8.ptr);
}

static void	ft_free_player_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.p.ptr);
	mlx_destroy_image(game->mlx, game->player.p1.ptr);
	mlx_destroy_image(game->mlx, game->player.p2.ptr);
	mlx_destroy_image(game->mlx, game->player.p3.ptr);
	mlx_destroy_image(game->mlx, game->player.p5.ptr);
	mlx_destroy_image(game->mlx, game->player.p6.ptr);
	mlx_destroy_image(game->mlx, game->player.p7.ptr);
	mlx_destroy_image(game->mlx, game->player.p8.ptr);
}

static void	ft_free_map_utils_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.ptr);
	mlx_destroy_image(game->mlx, game->wall1.ptr);
	mlx_destroy_image(game->mlx, game->wall2.ptr);
	mlx_destroy_image(game->mlx, game->exit_c.ptr);
	mlx_destroy_image(game->mlx, game->exit_o.ptr);
	mlx_destroy_image(game->mlx, game->key.ptr);
	mlx_destroy_image(game->mlx, game->floor.ptr);
}

void	ft_free_game(t_game *game)
{
	ft_free_player_img(game);
	ft_free_map_utils_img(game);
	ft_free_enemy_img(game);
	ft_free_map_game(game);
	mlx_destroy_window(game->mlx, game->win);
}
