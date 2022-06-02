/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:20:57 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 22:20:59 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_moves(t_game *game)
{
	static int	temp_move;
	char		*move;
	char		*last_move;

	move = ft_itoa(game->player.moves);
	if (move[0] == '0')
		free(move);
	mlx_string_put(game->mlx, game->win, POS_X_STR,
		POS_Y, STR_COLOR, "Moves:");
	if (game->player.moves > 0)
	{
		temp_move = game->player.moves;
		mlx_string_put(game->mlx, game->win, POS_X,
			POS_Y, STR_COLOR, move);
		free (move);
	}
	last_move = ft_itoa(temp_move);
	mlx_string_put(game->mlx, game->win, POS_X,
		POS_Y, STR_COLOR, last_move);
	free(last_move);
}
