/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:23:07 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 17:23:09 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
