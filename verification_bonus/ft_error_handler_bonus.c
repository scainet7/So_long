/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:36:27 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:36:33 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error_handler(t_game *game, char *str, int sweep)

{
	if (sweep == clean)
	{
		printf(CRED"%s\n", str);
		ft_free_game(game);
		exit(EXIT_FAILURE);
	}
	else if (sweep == mlx)
	{
		printf(CRED"%s\n", str);
		exit(EXIT_FAILURE);
	}
	if (sweep == map)
	{
		printf(CRED"%s\n", str);
		ft_free_map_game(game);
		exit(EXIT_FAILURE);
	}
	printf(CRED"%s\n", str);
	exit(EXIT_FAILURE);
}
