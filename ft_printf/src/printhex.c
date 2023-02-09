/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:23:27 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:01:44 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_width(t_parse *parser, int len)
{
	char	wchar;
	int		ret;

	ret = 0;
	wchar = ' ';
	if (parser->zero_padding && !(parser->negative_width)
		&& parser->precision == -1)
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
		parser->width -= 2;
	return (ret);
}

static void	get_typecasted(t_parse *parser, uintmax_t *ptr)
{
	if (!parser->typecast)
		*ptr = (unsigned int)va_arg(parser->args, unsigned int);
	else if (parser->typecast == 4)
		*ptr = (unsigned char)va_arg(parser->args, unsigned int);
	else if (parser->typecast == 2)
		*ptr = (unsigned short)va_arg(parser->args, unsigned int);
	else if (parser->typecast == 3)
		*ptr = (unsigned long long)va_arg(parser->args, unsigned long long);
	else if (parser->typecast == 1)
		*ptr = (unsigned long)va_arg(parser->args, unsigned long);
}

static	void	handle_hash(t_parse *parser, char **output, int *len, int *ret)
{
	if (parser->zero_padding || parser->precision > 0)
	{
		if (parser->capital)
			*ret += write(parser->fd, "0X", 2);
		else
			*ret += write(parser->fd, "0x", 2);
		if (parser->zero_padding && !(parser->negative_width))
			*len = 2;
	}
	else
		(*output) = ft_safejoin("0x", (*output));
}

int	printhex(t_parse *parser)
{
	int			ret;
	uintmax_t	ptr;
	char		*output;
	int			len;

	ret = 0;
	len = 0;
	get_typecasted(parser, &ptr);
	if (ptr == 0 && parser->precision == 0)
		output = ft_strdup("");
	else
		output = ft_luitoa_base(ptr, 16);
	if (parser->hash && ptr != 0)
		handle_hash(parser, &output, &len, &ret);
	if (parser->capital)
		ft_strup(&output);
	len += ft_strlen(output);
	if (!parser->negative_width && parser->precision < parser->width)
		ret += handle_width(parser, len);
	ret += handle_precision(parser, len);
	ret += write(parser->fd, output, ft_strlen(output));
	if (parser->width != ACCOUNTED || parser-> width > parser-> precision)
		ret += handle_width(parser, len);
	free(output);
	return (ret);
}
