/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:01:15 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 22:01:19 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_animations(t_game *game)
{
	if (game->key_enemy == 0 || game->key_enemy == 10)
	{
		ft_animate_enemy(game);
		ft_move_enemy(game);
	}
	ft_animate_player(game);
	return (0);
}
