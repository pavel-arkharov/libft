/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:15:59 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/23 11:18:09 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFF_SIZE 32
# define MAX_FD 12288

typedef enum e_bool { false, true }	t_bool;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstszie);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstszie);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putnbr(int n);
void			ft_bzero(void *s, size_t n);
void			ft_strclr(char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			ft_putendl(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s1, int c, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_calloc(size_t count, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_iscntrl(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_countdigits(intmax_t num);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_str_is_printable(char *s);
int				get_next_line(const int fd, char **line);
char			*ft_strstr(const char *hayst, const char *ndl);
char			*ft_strnstr(const char *hayst, const char *ndl, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnew(size_t size);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			*ft_itoa(long nbr);
char			*ft_itoa_base(long num, int base);
char			*ft_itoa_basex(long num, int base);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strsep(char **stringp, const char *delim);
char			*ft_chrsep(char **stringp, int ch);
char			*ft_uitoa(intmax_t num);
char			*ft_luitoa(uintmax_t num);
char			*ft_luitoa_base(uintmax_t num, int base);
char			**ft_strsplit(const char *s, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lsttemplate(const char *data);
void			ft_lstprint(t_list	*lst);
void			ft_lstpush(t_list **alst, t_list *new);
void			ft_lsttail(t_list **lst);
void			ft_printnode(t_list *lst);
void			ft_strup(char **str);
void			ft_tabdel(char ***tab);
long			ft_pow(int nbr, int power);
unsigned long	ft_sqrt(long nbr);
/* PRINTF */
typedef struct s_parse
{
	va_list	args;
	int		fd;
	int		hash;
	int		length;
	int		width;
	int		precision;
	int		zero_padding;
	int		negative_width;
	int		space;
	int		plus;
	int		capital;
	int		typecast;
}				t_parse;

# define SET 1
# define UNSET 0
# define ACCOUNTED -42

int				ft_vprintf(int fd, const char *format, va_list *args);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
char			*ft_safejoin(char *s1, char *s2);
int				find_specifier(char c);
void			parse_typecast(t_parse **parser, char **str);
void			parse_precision(t_parse **parser, char **str);
void			parse_width(t_parse **parser, char **str);
void			flush_parser(t_parse **parser);
t_parse			*init_parser(int fd);
int				writechar(t_parse *parser, char c);
char			getwchar(t_parse *parser);
void			add_one(char **str);
int				handle_nan_inf(t_parse *parser, char **str, int *ret);
int				if_nan_inf(long double arg, t_parse *parser, char **str);
void			handle_big_prec(int *precision, long *tail);
void			print_tail(long tail, int *ret, t_parse *parser);
void			print_dot(int hash, int prec, int *ret, t_parse *parser);

int				printpercent(t_parse *parser);
int				printchar(t_parse *parser);
int				printstring(t_parse *parser);
int				printpointer(t_parse *parser);
int				printsignedint(t_parse *parser);
int				printfloat(t_parse *parser);
int				printhex(t_parse *parser);
int				printoctal(t_parse *parser);
int				printuint(t_parse *parser);
int				printbinary(t_parse *parser);

#endif
