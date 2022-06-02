/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:16:41 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 17:16:46 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	else if (sweep == map)
	{
		printf(CRED"%s\n", str);
		ft_free_map_game(game);
		exit(EXIT_FAILURE);
	}
	printf(CRED"%s\n", str);
	exit(EXIT_FAILURE);
}
