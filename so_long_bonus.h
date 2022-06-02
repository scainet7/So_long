/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:39:42 by snino             #+#    #+#             */
/*   Updated: 2022/03/10 15:39:44 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <time.h>

# define UP 			13
# define DOWN 			1
# define LEFT 			0
# define RIGHT			2
# define ESC			53
# define IMG			64
# define CYEL			"\033[1;33m"
# define SUCCESS		"\x1B[32m"
# define RESET   		"\033[0m"
# define CRED			"\x1B[31m"
# define X_DESTROY		17
# define X_EXPOSE		12
# define POS_X			80
# define POS_X_STR		30
# define POS_Y			30
# define STR_COLOR		000000

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
	press_x,
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
	t_img	p1;
	t_img	p2;
	t_img	p3;
	t_img	p5;
	t_img	p6;
	t_img	p7;
	t_img	p8;
	int		x;
	int		y;
	int		moves;
	int		moves_plus;
}	t_player;

typedef struct s_enemy
{
	t_img	p;
	t_img	p1;
	t_img	p2;
	t_img	p3;
	t_img	p5;
	t_img	p6;
	t_img	p7;
	t_img	p8;
	int		x;
	int		y;
}	t_enemy;

typedef struct s_map
{
	int		x_len;
	int		y_len;
	char	**map;
	int		collection;
	int		person;
	int		enemy;
	int		nul;
	int		exit;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*map_name;
	int			key_press;
	int			key_press_anim;
	int			key_enemy;
	t_map		lines;
	t_player	player;
	t_enemy		enemy;
	t_img		wall;
	t_img		wall1;
	t_img		wall2;
	t_img		floor;
	t_img		exit_c;
	t_img		exit_o;
	t_img		key;
}	t_game;

int		ft_close_window(t_game *game);
int		ft_move_window(t_game *game);
int		ft_move_player(t_game *game, int move);
int		ft_move_enemy(t_game *game);
int		ft_animate_player(t_game *game);
int		ft_animate_enemy(t_game *game);
int		ft_animations(t_game *game);
int		ft_key_input(int key, t_game *game);
char	*ft_check_map(t_game *game);
void	ft_delay(int ms);
void	ft_print_moves(t_game *game);
void	ft_wright_enemy(t_game *game);
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
