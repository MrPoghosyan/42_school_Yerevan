/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:51:09 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 21:46:10 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//libc functionsi
//1
int		ft_isalpha(int c);
//2
int		ft_isdigit(int c);
//3
int		ft_isalnum(int c);
//4
int		ft_isascii(int c);
//5
int		ft_isprint(int c);
//6
int		ft_toupper(int c);
//7
int		ft_tolower(int c);
//8
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//9
int		ft_strlen(const char *s);
//10
char	*ft_strchr(const char *s, int c);
//11
char	*ft_strrchr(const char *s, int c);
//12
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//13
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//14
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//15
void	*ft_memset(void *b, int c, size_t len);
//16
void	*ft_memcpy(void *dst, const void *src, size_t n);
//17
void	*ft_memmove(void *dst, const void *src, size_t len);
//18
void	*ft_memchr(const void *s, int c, size_t n);
//19
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//20
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//21
void	ft_bzero(void *s, size_t n);
//22
int		ft_atoi(const char *str);
//23 
void	*ft_calloc(size_t count, size_t size);
//24
char	*ft_strdup(const char *s1);
//additionals
//1
char	*ft_substr(char const *s, unsigned int start, size_t len);
//2
char	*ft_strjoin(char const *s1, char const *s2);
//3
char	*ft_strtrim(char const *s1, char const *set);
//4
char	**ft_split(char const *s, char c);
//5
char	*ft_itoa(int n);
//6
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//7
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//8
void	ft_putchar_fd(char c, int fd);
//9
void	ft_putstr_fd(char *s, int fd);
//10
void	ft_putendl_fd(char *s, int fd);
//11
void	ft_putnbr_fd(int n, int fd);
#endif
