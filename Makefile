# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 18:07:48 by snino             #+#    #+#              #
#    Updated: 2022/12/05 19:55:48 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				:=	so_long

B_NAME 				:=	so_long_bonus

CC 					:=	gcc

CFLAGS 				:=	-Wall -Wextra -Werror -Imlx -g

LIBFT_A 			:=	libft.a

LIBF_DIR 			:=	libft/

LIBFT  				:=	$(addprefix $(LIBF_DIR), $(LIBFT_A))

LIB_mlx				:=	-L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRCS 				:=	so_long.c\
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

BONUS_SRCS			:=	so_long_bonus.c\
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

HEADER				:=	so_long.h

HEADER_B			:=	so_long_bonus.h

OBJ_DIR				:=	obj

B_OBJ_DIR			:=	obj_b

OBJ 				:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

BONUS_OBJ			:=	$(addprefix $(B_OBJ_DIR)/, $(patsubst %.c, %.o, $(BONUS_SRCS)))

.PHONY				:	all clean fclean bonus re

all 				:	$(NAME)

bonus 				:	$(B_NAME)

$(NAME)				:	$(HEADER) $(OBJ)
						@make -C $(LIBF_DIR)
						$(MAKE) -C ./minilibx
						$(CC) $(CFLAGS)  $(OBJ) $(LIB_mlx) $(LIBFT) -o $(NAME)

$(B_NAME)			:	$(HEADER_B) $(BONUS_OBJ)
						@make -C $(LIBF_DIR)
						$(MAKE) -C ./minilibx
						$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB_mlx) $(LIBFT) -o $(B_NAME)

$(OBJ_DIR)/%.o		:  	%.c $(HEADER)
						@mkdir -p $(OBJ_DIR)/read_and_move
						@mkdir -p $(OBJ_DIR)/verification
	 					$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)/%.o	:  	%.c $(HEADER)
						@mkdir -p $(B_OBJ_DIR)/read_and_move_bonus
						@mkdir -p $(B_OBJ_DIR)/verification_bonus
						@mkdir -p $(B_OBJ_DIR)/animations_bonus
	 					$(CC) $(CFLAGS) -c $< -o $@

clean				:
						@rm -rf $(OBJ)
						@rm -rf $(BONUS_OBJ)
						@make -C $(LIBF_DIR) clean

fclean				:	clean
						$(MAKE) -C ./minilibx clean
						@$(RM) $(NAME)
						@rm -rf obj
						@$(RM) $(B_NAME)
						@make -C $(LIBF_DIR) fclean

re					:	fclean all
