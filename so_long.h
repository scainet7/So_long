/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:07:14 by snino             #+#    #+#             */
/*   Updated: 2022/02/23 19:31:49 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define UP 			13
# define DOWN 			1
# define LEFT 			0
# define RIGHT			2
# define ESC			53
# define IMG			64
# define SUCCESS		"\x1B[32m"
# define RESET   		"\033[0m"
# define CRED			"\x1B[31m"
# define X_DESTROY		17
# define X_EXPOSE		12

enum e_direction
{
	left,
	right,
	up,
	down
};

enum e_exit
{
	leave,
	clean,
	mlx,
	map
};

typedef struct s_img
{
	void	*ptr;
}	t_img;

typedef struct s_player
{
	t_img	p;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_map
{
	int		x_len;
	int		y_len;
	char	**map;
	int		collection;
	int		person;
	int		nul;
	int		exit;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*map_name;
	t_map		lines;
	t_player	player;
	t_img		wall;
	t_img		floor;
	t_img		exit_c;
	t_img		exit_o;
	t_img		key;
}	t_game;

int		ft_close_window(t_game *game);
int		ft_move_window(t_game *game);
int		ft_move_player(t_game *game, int move);
int		ft_key_input(int key, t_game *game);
char	*ft_check_map(t_game *game);
void	ft_check_name(int argc, char **argv, t_game *game);
void	ft_check_map_string(t_game *game, char *line);
void	ft_check_verification_map(t_game *game);
void	ft_check_map_format(t_game *game);
void	ft_draft(t_game *game);
void	ft_init_map(t_game *game);
void	ft_error_handler(t_game *game, char *str, int sweep);
void	ft_free_game(t_game *game);
void	ft_free_map_game(t_game *game);
void	ft_exit_map(t_game *game);
void	ft_collect_item(t_game *game);

#endif
