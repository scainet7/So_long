/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_item_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:37:53 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:37:55 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_collect_item(t_game *game)
{
	if (game->lines.map[(game->player.y / IMG)][(game->player.x / IMG)] != 'C')
		return ;
	game->lines.map[(game->player.y / IMG)][(game->player.x / IMG)] = '0';
	game->lines.collection--;
}
