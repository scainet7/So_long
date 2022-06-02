/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:49:07 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 16:49:09 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_name_map(char *argv)
{
	size_t	res;
	char	*serch;

	serch = ".ber";
	res = ft_strlen(ft_strchr(argv, serch[0]));
	if (!ft_strstr(argv, serch) || res != 4)
		return (1);
	else
		return (0);
}

void	ft_check_name(int argc, char **argv, t_game *game)
{
	if (argc == 2 && !(ft_name_map(argv[1])))
		game->map_name = argv[1];
	else if (argc < 2)
		ft_error_handler(game, "Error\nNO_MAP", leave);
	else
	{
		if (ft_name_map(argv[1]))
			ft_error_handler(game, "Error\nINVALID_MAP_EXTENSION", leave);
		else
			ft_error_handler(game, "Error\nINVALID_NUM_ARGUMENTS", leave);
	}
}
