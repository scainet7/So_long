# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 18:07:48 by snino             #+#    #+#              #
#    Updated: 2022/02/23 18:41:10 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

B_NAME := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Imlx -g

LIBFT_A = libft.a

LIBF_DIR = libft/

LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

SRCS := so_long.c\
		 get_next_line/get_next_line.c\
		 get_next_line/get_next_line_utils.c\
		 $(addprefix read_and_move/,\
		 ft_init_map.c\
		 ft_key_input.c\
		 ft_close_window.c\
		 ft_move_player.c\
		 ft_exit_map.c\
		 ft_collect_item.c\
		 ft_move_window.c\
		 ft_draft.c)\
		 $(addprefix verification/,\
		 ft_check_name.c\
		 ft_error_handler.c\
		 ft_check_map_string.c\
		 ft_check_verification_map.c\
		 ft_free_game.c\
		 ft_free_map_game.c\
		 ft_check_map_format.c\
		 ft_check_map.c)\

BONUS_SRCS := so_long_bonus.c\
				get_next_line/get_next_line.c\
                get_next_line/get_next_line_utils.c\
                $(addprefix animations_bonus/,\
                ft_animate_enemy_bonus.c\
                ft_animations_bonus.c\
                ft_delay_bonus.c\
                ft_animate_player_bonus.c)\
                $(addprefix read_and_move_bonus/,\
                ft_init_map_bonus.c\
                ft_key_input_bonus.c\
                ft_print_moves_bonus.c\
                ft_close_window_bonus.c\
                ft_move_player_bonus.c\
                ft_move_enemy_bonus.c\
                ft_exit_map_bonus.c\
                ft_collect_item_bonus.c\
                ft_move_window_bonus.c\
                ft_wright_enemy_bonus.c\
                ft_draft_bonus.c)\
                $(addprefix verification_bonus/,\
                ft_check_name_bonus.c\
                ft_error_handler_bonus.c\
                ft_check_map_string_bonus.c\
                ft_check_verification_map_bonus.c\
                ft_free_game_bonus.c\
                ft_free_map_game_bonus.c\
                ft_check_map_format_bonus.c\
                ft_check_map_bonus.c)\

LIB := -L ./minilibx -lmlx -framework OpenGL -framework AppKit

HEADER		:= so_long.h

HEADER_B	:= so_long_bonus.h

OBJ := $(SRCS:%.c=%.o)

BONUS_OBJ := $(BONUS_SRCS:%.c=%.o)

all : $(NAME)

bonus : $(B_NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./minilibx
	@make -C $(LIBF_DIR)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) $(LIB) -o $(NAME)

$(B_NAME) : $(BONUS_OBJ)
		$(MAKE) -C ./minilibx
		@make -C $(LIBF_DIR)
		$(CC) $(CFLAGS)  $(BONUS_OBJ) $(LIBFT) $(LIB) -o $(B_NAME)

clean:
	@make -C $(LIBF_DIR) clean
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C ./minilibx clean
	@make -C $(LIBF_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(B_NAME)

re: fclean all
