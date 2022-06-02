/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wright_enemy_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:24:29 by snino             #+#    #+#             */
/*   Updated: 2022/03/12 22:24:32 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_check_enemy(t_game *game, int y_num, int x_num)
{
	if (game->lines.map[y_num][x_num] == 'C'
	&& game->lines.map[y_num][x_num + 1] == '0'
	&& game->lines.map[y_num][x_num + 2] == '0'
	&& game->lines.map[y_num][x_num + 3] == '0')
	{
		game->lines.enemy++;
		game->lines.map[y_num][x_num + 1] = 'Y';
	}
	else if (game->lines.map[y_num][x_num] == 'C'
	&& game->lines.map[y_num][x_num - 1] == '0'
	&& game->lines.map[y_num][x_num - 2] == '0'
	&& game->lines.map[y_num][x_num - 3] == '0')
	{
		game->lines.enemy++;
		game->lines.map[y_num][x_num - 1] = 'Y';
	}
}

void	ft_wright_enemy(t_game *game)
{
	int	y_num;
	int	x_num;

	y_num = 0;
	game->lines.enemy = 0;
	while (game->lines.map[y_num])
	{
		x_num = 0;
		while (game->lines.map[y_num][x_num])
		{
			ft_check_enemy(game, y_num, x_num);
			if (game->lines.enemy == 1)
				break ;
			x_num++;
		}
		y_num++;
	}
}
