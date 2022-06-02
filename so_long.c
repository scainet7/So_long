/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:06:19 by snino             #+#    #+#             */
/*   Updated: 2022/02/23 19:42:56 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*check_map;
	t_game	game;

	ft_check_name(argc, argv, &game);
	game.mlx = mlx_init();
	check_map = ft_check_map(&game);
	game.lines.map = ft_split(check_map, '\n');
	free(check_map);
	ft_check_verification_map(&game);
	game.win = mlx_new_window(game.mlx, ((game.lines.x_len + 1) * IMG),
			((game.lines.y_len + 1) * IMG), "./so_long");
	ft_draft(&game);
	ft_init_map(&game);
	mlx_key_hook(game.win, &ft_key_input, &game);
	mlx_hook(game.win, X_DESTROY, (0L), &ft_close_window, &game);
	mlx_hook(game.win, X_EXPOSE, (1L << 15), &ft_move_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
