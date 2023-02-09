/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:19:20 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:06:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_parse
{
	va_list	args;
	int     fd;
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

int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
char	*ft_safejoin(char *s1, char *s2);
int		find_specifier(char c);
void	parse_typecast(t_parse **parser, char **str);
void	parse_precision(t_parse **parser, char **str);
void	parse_width(t_parse **parser, char **str);
void	flush_parser(t_parse **parser);
t_parse	*init_parser(int fd);
int		writechar(t_parse *parser, char c);
char	getwchar(t_parse *parser);
void	add_one(char **str);
int		handle_nan_inf(t_parse *parser, char **str, int *ret);
int		if_nan_inf(long double arg, t_parse *parser, char **str);
void	handle_big_prec(int *precision, long *tail);
void	print_tail(long tail, int *ret, t_parse *parser);
void	print_dot(int hash, int prec, int *ret, t_parse *parser);

int		printpercent(t_parse *parser);
int		printchar(t_parse *parser);
int		printstring(t_parse *parser);
int		printpointer(t_parse *parser);
int		printsignedint(t_parse *parser);
int		printfloat(t_parse *parser);
int		printhex(t_parse *parser);
int		printoctal(t_parse *parser);
int		printuint(t_parse *parser);
int		printbinary(t_parse *parser);

#endif