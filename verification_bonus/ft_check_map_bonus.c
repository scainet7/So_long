/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:35:27 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:35:32 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_check_map(t_game *game)
{
	char	*line_map;
	char	*map_string;
	int		fd;

	map_string = ft_strdup_gnl("");
	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
	{
		free(map_string);
		ft_error_handler(game, "Error\nNO_MAP_IN_FILE", mlx);
	}
	while (1)
	{
		line_map = get_next_line(fd);
		if (!line_map)
		{
			free(line_map);
			break ;
		}
		map_string = ft_strjoin_gnl(map_string, line_map);
		free(line_map);
	}
	close(fd);
	ft_check_map_string(game, map_string);
	return (map_string);
}
