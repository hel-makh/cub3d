# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 11:42:59 by hel-makh          #+#    #+#              #
#    Updated: 2022/08/25 15:49:04 by hel-makh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			=	mandatory/includes/cub3d.h

HEADER_BONUS	=	bonus/includes/cub3d.h

NAME			=	cub3d

NAME_BONUS		=	cub3d_bonus

FILES			=	utils/ft_get_current_time.c\
					utils/ft_create_trgb.c\
					utils/ft_get_distance.c\
					utils/ft_is_in_circle.c\
					utils/ft_radian_degree.c\
					utils/ft_radian_operations.c\
					parsing/ft_import_map.c\
					parsing/ft_parse_textures.c\
					parsing/ft_get_textures.c\
					parsing/ft_parse_map.c\
					parsing/ft_component_surroundings.c\
					movements/ft_get_player_position.c\
					movements/ft_player_movement.c\
					rendering/ft_get_hit_wall.c\
					rendering/ft_frame_rendering.c\
					rendering/ft_draw_rays.c\
					rendering/ft_render_3d_scene.c\
					rendering/ft_draw_floor_ceilling.c\
					other/ft_exit_game.c\
					main.c

FILES_BONUS		=	utils/ft_get_current_time.c\
					utils/ft_create_trgb.c\
					utils/ft_get_distance.c\
					utils/ft_is_in_circle.c\
					utils/ft_radian_degree.c\
					utils/ft_radian_operations.c\
					utils/ft_play_sound.c\
					utils/ft_collectible_lstfuncs.c\
					utils/ft_door_lstfuncs.c\
					utils/ft_render_lstfuncs.c\
					parsing/ft_import_map.c\
					parsing/ft_parse_textures.c\
					parsing/ft_get_textures.c\
					parsing/ft_parse_map.c\
					parsing/ft_component_surroundings.c\
					movements/ft_get_player_position.c\
					movements/ft_player_movement.c\
					rendering/ft_get_hit_wall.c\
					rendering/ft_frame_rendering.c\
					rendering/ft_door_opening.c\
					rendering/ft_render_minimap.c\
					rendering/ft_draw_rays.c\
					rendering/ft_render_3d_scene.c\
					rendering/ft_render_sprites.c\
					rendering/ft_draw_floor_ceilling.c\
					other/ft_exit_game.c\
					main.c

SRCS_DIR		=	mandatory/srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(FILES))

SRCS_BONUS_DIR	=	bonus/srcs/
SRCS_BONUS		=	$(addprefix $(SRCS_BONUS_DIR), $(FILES_BONUS))

OBJS_DIR		=	mandatory/objs/
OBJS			=	$(patsubst %.c, %.o, $(addprefix $(OBJS_DIR), $(FILES)))

OBJS_BONUS_DIR	=	bonus/objs/
OBJS_BONUS		=	$(patsubst %.c, %.o, $(addprefix $(OBJS_BONUS_DIR), $(FILES_BONUS)))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

LIBFT_DIR		=	./Libft
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_IFLAGS	=	-ILibft

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_DIR		=	mlx_macos
	MLX			=	$(MLX_DIR)/libmlx.a
	MLX_IFLAGS	=	-Imlx_macos
	MLX_LFLAGS	=	-framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S), Linux)
	MLX_DIR		=	mlx_linux
	MLX			=	$(MLX_DIR)/libmlx.a
	MLX_IFLAGS	=	-I/usr/include -Imlx_linux -O3
	MLX_LFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c				$(HEADER)
					@mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(LIBFT_IFLAGS) $(MLX_IFLAGS) -c $< -o $@

$(OBJS_BONUS_DIR)%.o:$(SRCS_BONUS_DIR)%.c	$(HEADER_BONUS)
					@mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(LIBFT_IFLAGS) $(MLX_IFLAGS) -c $< -o $@

$(NAME):			$(HEADER) $(OBJS) $(LIBFT) $(MLX)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_LFLAGS) -o $(NAME)

$(NAME_BONUS):		$(HEADER_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX)
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLX_LFLAGS) -o $(NAME_BONUS)

all:				$(NAME)

bonus:              $(NAME_BONUS)

$(LIBFT):
					make -C $(LIBFT_DIR)

$(MLX):
					make -C $(MLX_DIR)

clean:
					rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					rm -rf $(NAME) $(BONUS)
					make fclean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)

re:					fclean all

.PHONY:				all clean fclean re