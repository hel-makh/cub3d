HEADER			=	includes/cub3d.h

NAME			=	cub3d

FILES			=	utils/ft_get_current_time.c\
					utils/ft_create_trgb.c\
					utils/ft_get_distance.c\
					utils/ft_is_in_circle.c\
					utils/ft_radian_operations.c\
					parsing/ft_import_map.c\
					parsing/ft_parse_textures.c\
					parsing/ft_parse_map.c\
					parsing/ft_component_surroundings.c\
					raycasting/ft_draw_rays.c\
					other/ft_get_player_position.c\
					other/ft_loop_hook.c\
					other/ft_player_movement.c\
					other/ft_render_minimap.c\
					main.c

SRCS_DIR		=	srcs/

SRCS			=	$(addprefix $(SRCS_DIR), $(FILES))

OBJS_DIR		=	objs/

OBJS			=	$(patsubst %.c, %.o, $(addprefix $(OBJS_DIR), $(FILES)))

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_IFLAGS	+=	-Imlx
	MLX_LFLAGS	+=	-lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S), Linux)
	MLX_IFLAGS	+=	-I/usr/include -Imlx_linux -O3
	MLX_LFLAGS	+=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

LIBFT_DIR		=	./Libft

LIBFT			=	$(LIBFT_DIR)/libft.a

RM				=	rm -rf

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c		$(HEADER)
					@mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(MLX_IFLAGS) -c $< -o $@

$(NAME):			$(HEADER) $(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LFLAGS) -o $(NAME)

all:				$(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR)

clean:
					$(RM) $(OBJS_DIR)
					make clean -C $(LIBFT_DIR)

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re