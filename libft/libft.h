/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:44:27 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/11 07:20:13 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
#define

#include <string.h>

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

void	ft_memdel(void **ap);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

void	ft_putchar(char c);

void	ft_putstr(char const *s);

char	*ft_strcat(char *restrict s1, const char *restrict s2);

char	*ft_strchr(const char *s, int c);

void	ft_strclr(char *s);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

void	ft_strdel(char **as);

char	*ft_strdup(const char *str);

int		ft_strqu(char const *s1, char const *s2);

int		ft_strlen(const char *s);

char	*ft_strcat(char *restrict s1, const char *restrict s2, size_t n);

int		ft_strcmp(const char *s1, const char *s2, size_t n);

char	*ft_strcpy(char *dst, const char *src, size_t len);

int		ft_strnequ(char const *s1, char const *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strchr(const char *s, int c);

char	*ft_strstr(const char *haystack, const char *needle);

int		ft_tolower(int c);

int		ft_toupper(int c);

#endif

