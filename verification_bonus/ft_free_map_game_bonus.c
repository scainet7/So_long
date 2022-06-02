/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_game_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:37:05 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:37:09 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free_map_game(t_game *game)
{
	int	y_num;

	y_num = 0;
	while (game->lines.map[y_num])
	{
		free(game->lines.map[y_num]);
		y_num++;
	}
	free(game->lines.map);
}
