/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:28:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/07 12:42:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isnumber(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_arrlen(char **arr);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrstr(const char *haystack, const char *needle);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **array);
void	*ft_free_3d(char ***array);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_joinstrs(char **array, char c);
char	*ft_stradd(char const *s1, char const *s2);
char	*ft_strnadd(char const *s1, char const *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_arr_has_str(char **arr, char *str);
char	*ft_replace_str( char *s1, const char *s2,
			unsigned int start, unsigned int len);
char	**ft_arrdup(char **array);
char	**ft_split(char const *s, char c);
char	**ft_add_str2arr(char **array, char *str);
char	**ft_replace_arr( char **arr1, char **arr2,
			unsigned int start, unsigned int size);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);

#endif
