HEADER			=	includes/cub3d.h

NAME			=	cub3d

MAIN			=	main.c

SRCS			=	srcs/ft_init_vars.c\
					srcs/ft_import_map.c\
					srcs/ft_parse_textures.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# LIBXFLAGS		=	-lmlx -framework OpenGL -framework AppKit

LIBFT_DIR		=	./Libft

LIBFT			=	./Libft/libft.a

RM				=	rm -f

%.o:%.c			$(HEADER) 
				$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

$(NAME):		$(HEADER) $(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

# $(NAME):		$(HEADER) $(LIBFT) $(OBJS)
# 				$(CC) $(CFLAGS) $(LIBXFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

all:			$(NAME)

$(LIBFT):
				# make -C $(LIBFT_DIR)

clean:
				$(RM) $(OBJS)
				# make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				# make fclean -C $(LIBFT_DIR)

re:				fclean all

.PHONY:			all clean fclean re