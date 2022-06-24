HEADER			=	includes/cub3d.h

NAME			=	cub3d

SRCS			=	srcs/utils/ft_radian_operations.c\
					srcs/utils/ft_get_distance.c\
					srcs/utils/ft_is_in_circle.c\
					srcs/utils/ft_create_trgb.c\
					srcs/parsing/ft_import_map.c\
					srcs/parsing/ft_parse_textures.c\
					srcs/parsing/ft_parse_map.c\
					srcs/parsing/ft_component_surroundings.c\
					srcs/raycasting/ft_draw_rays.c\
					srcs/other/ft_get_player_position.c\
					srcs/other/ft_loop_hook.c\
					srcs/other/ft_player_movement.c\
					srcs/other/ft_render_minimap.c\
					srcs/main.c

OBJS			=	$(SRCS:.c=.o)

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

LIBFT			=	${LIBFT_DIR}/libft.a

RM				=	rm -f

%.o:%.c			$(HEADER) 
				$(CC) $(CFLAGS) ${MLX_IFLAGS} -c $< -o $@

$(NAME):		$(HEADER) $(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LFLAGS) -o $(NAME)

all:			$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				make fclean -C $(LIBFT_DIR)

re:				fclean all

.PHONY:			all clean fclean re