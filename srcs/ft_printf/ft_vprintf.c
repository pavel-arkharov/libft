/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:10:04 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/23 11:14:35 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	int	ft_abs(int num, t_parse *parser, int is_prec)
{
	if (num < 0)
	{
		if (!is_prec)
			parser->negative_width = 1;
		else
			return (-1);
		return (-num);
	}
	return (num);
}

static void	parse_flags(t_parse **parser, char **str)
{
	(*parser)->length = UNSET;
	if (**str == '#')
		(*parser)->hash = SET;
	if (**str == '0')
		(*parser)->zero_padding = SET;
	if (**str == '-')
		(*parser)->negative_width = SET;
	if (**str == '+')
		(*parser)->plus = SET;
	if (**str == ' ')
		(*parser)->space = SET;
	if (**str == '*')
		(*parser)->width = ft_abs(va_arg((*parser)->args, int), *parser, 0);
	if (**str >= '1' && **str <= '9')
		parse_width(parser, str);
	if (**str == '.')
		parse_precision(parser, str);
	if (**str == 'l' || **str == 'L' || **str == 'h')
		parse_typecast(parser, str);
}

static void	parse_specifier(t_parse *parser, char c)
{
	if (c == 'c')
		parser->length += printchar(parser);
	if (c == '%')
		parser->length += printpercent(parser);
	if (c == 's')
		parser->length += printstring(parser);
	if (c == 'p')
		parser->length += printpointer(parser);
	if (c == 'i' || c == 'd')
		parser->length += printsignedint(parser);
	if (c == 'u')
		parser->length += printuint(parser);
	if (c == 'f')
		parser->length += printfloat(parser);
	if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			parser->capital = 1;
		parser->length += printhex(parser);
	}
	if (c == 'o')
		parser->length += printoctal(parser);
	if (c == 'b')
		parser->length += printbinary(parser);
}

static int	parse_format(char **str, t_parse *parser)
{
	*str += 1;
	if (!(**str))
		return (0);
	flush_parser(&parser);
	while (!find_specifier(**str))
	{
		parse_flags(&parser, str);
		*str += 1;
		if (!(**str))
			return (0);
	}
	parse_specifier(parser, **str);
	*str += 1;
	return (parser->length);
}

int	ft_vprintf(int fd, const char *format, va_list *args)
{
	int		ret;
	char	*reader;
	t_parse	*parser;

	ret = 0;
	parser = init_parser(fd);
	reader = (char *)format;
	va_copy(parser->args, *args);
	while (*reader)
	{
		if (*reader == '%')
			ret += parse_format(&(reader), parser);
		else
			ret += write(parser->fd, &(*reader++), 1);
	}
	va_end(parser->args);
	free(parser);
	return (ret);
}
