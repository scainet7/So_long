/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:18 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 15:55:21 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_collect_item(t_game *game)
{
	if (game->lines.map[(game->player.y / IMG)][(game->player.x / IMG)] != 'C')
		return ;
	game->lines.map[(game->player.y / IMG)][(game->player.x / IMG)] = '0';
	game->lines.collection--;
}
