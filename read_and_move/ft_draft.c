/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:51 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 15:56:01 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_player_draft(t_game *game)
{
	int	y;
	int	x;

	game->player.p.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/player2R.xpm", &x, &y);
}

static void	ft_map_draft(t_game *game)
{
	int	y;
	int	x;

	game->wall.ptr = mlx_xpm_file_to_image(
			game->mlx, "texture/wall.xpm", &x, &y);
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
}
