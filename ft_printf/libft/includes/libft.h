/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:28:39 by dbendu            #+#    #+#             */
/*   Updated: 2019/12/16 19:36:25 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

# define MAX_INT		(2147483647)
# define MIN_INT		(-2147483648)
# define MAX_SIZE_T		(18446744073709551615llu)
# define MAX_LLONG		(9223372036854775807ll)
# define MIN_LLONG		-MAX_LLONG
# define GNL_BUFF_SIZE	1000

# define ULL			unsigned long long
# define UL				unsigned long

# define TOSTR(a)		#a
# define TRUE 1
# define FALSE 0

typedef char t_bool;

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
	struct s_list		*end;
}						t_list;

typedef struct			s_dlist
{
	void				*data;
	struct s_dlist		*next;
	struct s_dlist		*prev;
	struct s_dlist		*end;
}						t_dlist;

int						ft_is_hex(char c);
void					ft_error(const char *error_msg, int error_code);

int						ft_get_next_line(int fd, char **line);
int						ft_mod_num(int num);

void					ft_lstpop(t_list **list);
void					ft_lstpurge(t_list **list);
void					ft_lstdelone(t_list **list);
void					ft_lstpopback(t_list **list);
size_t					ft_lstsize(const t_list *list);
void					ft_lstdelete(t_list **list, t_list **del);
void					ft_lstextend(t_list **list, t_list **add);
void					ft_lstappend(t_list **list, t_list *elem);
void					ft_lstadd(t_list **list, t_list *new_elem);
void					ft_lstiter(t_list *list, void(*f)(t_list *elem));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));

void					ft_dlstpurge(t_dlist **list);
size_t					ft_dlstsize(const t_dlist *list);
void					ft_dlstadd(t_dlist **list, t_dlist *elem);
t_dlist					*ft_dlstnew(const void *data, size_t size);
void					ft_dlstappend(t_dlist **list, t_dlist *elem);
void					ft_dlstiter(t_dlist *list, void (*f)(t_dlist *elem));

void					*ft_memalloc(size_t size);
void					*ft_memset(void *dest, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t num);
void					*ft_memchr(const void *memptr, int val, size_t num);
void					*ft_memnchr(const void *memptr, int val, size_t num);
void					*ft_memmove(void *dest, const void *src, size_t num);
void					*ft_memrchr(const void *memptr, int val, size_t num);
void					*ft_memrnchr(const void *memptr, int val, size_t num);
void					*ft_memccpy(void *d, const void *s, int ch,
						size_t cnt);
int						ft_memcmp(const void *mem1, const void *mem2,
						size_t num);

void					ft_putnbr(int n);
void					ft_putchar(char c);
void					ft_putstr(const char *str);
void					ft_putendl(const char *str);
void					ft_putnbr_fd(int n, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *str, int fd);
void					ft_putendl_fd(const char *str, int fd);

char					*ft_mitoa(__int128_t num,
						unsigned base, unsigned size);
char					*ft_itoa_buf(__int128_t num, char *str, unsigned base,
																unsigned size);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
void					ft_swap(void *a, void *b, size_t size);
__int128_t				ft_atoi(const char *str);
size_t					sizeof_num(__int128_t num, unsigned base);

char					*ft_strrev(char *str);
void					ft_strclr(char *str);
void					ft_strdel(char **str);
char					*ft_strtrim(char *str);
char					*ft_strnew(size_t size);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
void					ft_striter(char *s, void(*f)(char*));
char					*ft_strrchr(const char *str, int ch);
char					**ft_strsplit(const char *str, char c);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strcpy(char *dest, const char *src);
int						ft_strequ(const char *s1, const char *s2);
char					*ft_strchr(const char *str, int character);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strmap(const char *str, char (*f)(char));
int						ft_strcmp(const char *str1, const char *str2);
char					*ft_strstr(const char *str, const char *find);
char					*ft_strncpy(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
void					ft_striteri(char *str,
						void (*f)(unsigned int, char *));
char					*ft_strncat(char *destptr,
						const char *srcptr, size_t num);
int						ft_strncmp(const char *str1,
						const char *str2, size_t num);
char					*ft_strnstr(const char *str,
						const char *find, size_t len);
char					*ft_strmapi(char const *str,
						char (*f)(unsigned int, char));
char					*ft_strsub(const char *str,
						unsigned int start, size_t len);

int						ft_abs(int a);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_min(int a, int b);
int						ft_max(int a, int b);
void					ft_arrdel(void ***arr);
int						ft_minn(int amount, ...);
int						ft_maxn(int amount, ...);
long double				ft_dpow(long double num, int n);
void					print_bits(void *a, size_t size);
void					printn_bits(void *a, size_t size);
unsigned long long		ft_ipow(unsigned long long num, int n);
char					*ft_itoa(long long int num);

#endif
