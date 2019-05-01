/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:49:04 by ndombre           #+#    #+#             */
/*   Updated: 2017/07/29 17:19:07 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FT_STDOUT 1
# define FT_ERROUT 2

# define FT_LIBFT_DEBUG_NO

# ifdef LOVE
#  include "love.h"
# endif

# include <string.h>
# include <wctype.h>
# include <inttypes.h>
# include <time.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_htime
{
	int		sec;
	int		min;
	int		hour;
	int		day;
	int		moth;
	int		year;
	int		dayname;
	int		zone;
}				t_htime;

int				get_next_line(const int fd, char **line);

int				ft_printf(char *str, ...);
int				ft_fprintf(int fd, char *str, ...);

t_htime			gethtime(time_t t, int local);
int				ft_print_time(t_htime t);

char			*ft_mutoa(uintmax_t nb);
char			*ft_mitoa(intmax_t nb);
char			*ft_itoa_basse(int i, int base);

char			*ft_mutoa_base(uintmax_t nb, int basse);
char			*ft_mutoa_mbase(uintmax_t nb, int basse);
char			*ft_mutoa_hex_pre(uintmax_t nb);
char			*ft_mutoa_mhex_pre(uintmax_t nb);

char			*ft_strjoinfn(char *s1, char *s2);
char			*ft_strjoinnf(char *s1, char *s2);
char			*ft_strjoinff(char *s1, char *s2);

size_t			ft_strwlen(char const *str);
int				ft_wtoc(unsigned char reeltab[4], const wchar_t c);
int				ft_wcstombs(char *d, const wchar_t *src, size_t n);
char			*ft_wcstostr(wchar_t const *n);
char			*ft_wctoms(wchar_t src);
int				ft_wtoclen(const wchar_t c);
char			*ft_wcsntostr(wchar_t const *n, size_t max);
char			*ft_wcntoms(wchar_t wc, size_t pre);

void			*ft_memset(void *m, int c, size_t len);
void			ft_bzero(void *m, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memdup(const void *m, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_artoi(const char *str, int *err);
int				ft_strtest(char const *s, int (*f)(int));
int				ft_strntest(char const *s, int (*f)(int), size_t n);

int				ft_isalpha(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strinc(char c, char *str);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_puterrl(char const *s);
void			ft_puthex(unsigned int i);
int				ft_putbasse(unsigned int i, char *set);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_print_memory(void const *d, size_t s);

void			*ft_malloc(size_t s);
void			ft_free(void *p);
int				ft_write(int fd, char const *s, size_t n);

void			ft_error(char *s, int exit_code);

#endif
