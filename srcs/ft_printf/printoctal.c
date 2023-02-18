/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoctal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:25:57 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/16 18:57:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	handle_width(t_parse *parser, int len)
{
	char	wchar;
	int		ret;

	ret = 0;
	wchar = ' ';
	if (parser->hash && !parser->negative_width)
		len++;
	if (parser->zero_padding && !(parser->negative_width))
		wchar = '0';
	while ((parser->precision > 0 && parser->precision > len
			&& parser->width > parser->precision) || (parser->precision > 0
			&& parser->precision <= len && parser->width > len)
		|| (parser->precision <= 0 && parser->width > len))
	{
		ret += write (1, &wchar, 1);
		parser->width--;
	}
	parser->width = ACCOUNTED;
	return (ret);
}

static int	handle_precision(t_parse *parser, int len)
{
	int	ret;

	ret = 0;
	while (parser->precision > len++)
		ret += write(parser->fd, "0", 1);
	if (parser->hash)
		parser->width -= 1;
	return (ret);
}

static void	get_typecasted(t_parse *parser, uintmax_t *num)
{
	if (parser->typecast == 4)
		*num = (unsigned char)va_arg(parser->args, unsigned int);
	else if (parser->typecast == 2)
		*num = (unsigned short)va_arg(parser->args, unsigned int);
	else if (parser->typecast == 3)
		*num = (unsigned long long)va_arg(parser->args, unsigned long long);
	else if (parser->typecast == 1)
		*num = (unsigned long)va_arg(parser->args, unsigned long);
	else
		*num = (unsigned int)va_arg(parser->args, unsigned int);
}

static	int	handle_hash(int *len, t_parse *parser)
{
	*len += 1;
	return (write(parser->fd, "0", 1));
}

int	printoctal(t_parse *parser)
{
	int			ret;
	int			len;
	uintmax_t	num;
	char		*output;

	ret = 0;
	get_typecasted(parser, &num);
	if (num == 0 && parser->precision != -1 && !parser->hash)
		output = ft_strdup("");
	else
		output = ft_luitoa_base(num, 8);
	len = ft_strlen(output);
	if (!parser->negative_width && parser->precision < parser->width)
		ret += handle_width(parser, len);
	if (parser->hash && num != 0)
		ret += handle_hash(&len, parser);
	if (parser->precision != -1)
		ret += handle_precision(parser, len);
	ret += write(parser->fd, output, ft_strlen(output));
	if (parser->width != ACCOUNTED || parser->width > parser->precision)
		ret += handle_width(parser, len);
	free(output);
	return (ret);
}
