/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:38:23 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:38:26 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->lines.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf("MOVE: %d\n"SUCCESS"YOU_WIN!\n"RESET, game->player.moves);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->lines.map[(game->player.y / IMG)][(
			game->player.x / IMG)] == 'Y')
	{
		printf(CRED"GAME_OVER! YOU_DIED!\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->key_press == ESC)
	{
		printf(CYEL"YOU_EXIT_GAME\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
}
