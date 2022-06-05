INCDIR			=	.

HEADER			=	libft.h

NAME			=	libft.a

SRCS			=	ft_isalpha.c\
					ft_isdigit.c\
					ft_isalnum.c\
					ft_isascii.c\
					ft_isprint.c\
					ft_isspace.c\
					ft_arrlen.c\
					ft_strlen.c\
					ft_memset.c\
					ft_bzero.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_strcpy.c\
					ft_strlcpy.c\
					ft_strcat.c\
					ft_strlcat.c\
					ft_toupper.c\
					ft_tolower.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_strcmp.c\
					ft_strncmp.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_strstr.c\
					ft_strnstr.c\
					ft_atoi.c\
					ft_calloc.c\
					ft_free.c\
					ft_strdup.c\
					ft_substr.c\
					ft_strjoin.c\
					ft_joinstrs.c\
					ft_stradd.c\
					ft_strnadd.c\
					ft_strtrim.c\
					ft_arr_has_str.c\
					ft_replace_str.c\
					ft_arrdup.c\
					ft_split.c\
					ft_add_str2arr.c\
					ft_replace_arr.c\
					ft_itoa.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					get_next_line.c

OBJS			=	$(SRCS:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				ar rc $@ $^
				ranlib $@

all:			$(NAME)

clean:
				$(RM) $(OBJS)
			
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re