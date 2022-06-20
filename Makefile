HEADER			=	includes/cub3d.h

NAME			=	cub3d

MAIN			=	main.c

SRCS			=	srcs/ft_init_vars.c\
					srcs/ft_import_map.c\
					srcs/ft_parse_textures.c\
					srcs/ft_parse_map.c\
					srcs/ft_component_surroundings.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_IFLAGS	+=	-Imlx
	MLX_LFLAGS	+=	-lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S), Linux)
	MLX_IFLAGS	+=	-I/usr/include -Imlx_linux -O3
	MLX_LFLAGS	+=	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

LIBFT_DIR		=	./Libft

LIBFT			=	./Libft/libft.a

RM				=	rm -f

%.o:%.c			$(HEADER) 
				$(CC) $(CFLAGS) ${MLX_IFLAGS} -c $< -o $@

$(NAME):		$(HEADER) $(LIBFT) $(OBJS)
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