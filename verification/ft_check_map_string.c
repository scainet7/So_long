/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:47:51 by snino             #+#    #+#             */
/*   Updated: 2022/03/08 16:47:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_string(t_game *game, char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0' || line[i] == '\n')
	{
		free(line);
		ft_error_handler(game, "Error\nINVALID_MAP", mlx);
	}
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] != '1')
		{
			free(line);
			ft_error_handler(game, "Error\nINVALID_MAP", mlx);
		}
		i++;
	}
}
