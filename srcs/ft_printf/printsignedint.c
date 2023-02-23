/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:10 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/23 09:40:55 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	get_typecasted(t_parse *parser, intmax_t *num)
{
	if (parser->typecast == 4)
		*num = (signed char)va_arg(parser->args, int);
	else if (parser->typecast == 2)
		*num = (short)va_arg(parser->args, int);
	else if (parser->typecast == 3)
		*num = (long long)va_arg(parser->args, long long);
	else if (parser->typecast == 1)
		*num = (long)va_arg(parser->args, long);
	else
		*num = (int)va_arg(parser->args, int);
}

char	*get_num(t_parse *parser, int *sign)
{
	intmax_t	num;

	*sign = 0;
	get_typecasted(parser, &num);
	if (num < 0)
	{
		*sign = 1;
		num *= -1;
	}
	if (num == 0 && parser->precision == 0)
		return (ft_strdup(""));
	else
		return (ft_uitoa(num));
}

void	negativecase(t_parse *parser, int *ret, int sign, char *output)
{
	char	wchar;
	int		len;

	len = (int)ft_strlen(output);
	wchar = getwchar(parser);
	if (parser->space && !sign && !(parser->plus))
		*ret += writechar(parser, ' ');
	if (parser->plus && !sign && parser->width > len
		&& wchar == '0')
		*ret += writechar(parser, '+');
	else if (parser->plus && !sign)
		parser->width--;
	while (parser->width-- > len + sign && parser->width
		>= parser->precision + sign)
		*ret += write(parser->fd, &wchar, 1);
	if (sign && wchar != '0')
		*ret += write (1, "-", 1);
	else if (parser->plus && wchar == ' ' && ft_strchr(output, '+') == 0)
		*ret += write(parser->fd, "+", 1);
	while (parser->precision-- > len)
		*ret += write(parser->fd, "0", 1);
	*ret += write(parser->fd, output, ft_strlen(output));
}

void	normalcase(t_parse *parser, int *ret, int sign, char *output)
{
	char	wchar;
	int		len;

	len = (int)ft_strlen(output);
	wchar = getwchar(parser);
	if (sign)
		*ret += write(parser->fd, "-", 1);
	if (parser->plus && wchar == ' ' && ft_strchr(output, '+') == 0)
		*ret += writechar(parser, '+');
	while (parser->precision-- > len && parser->width--)
		*ret += write(parser->fd, "0", 1);
	*ret += write(parser->fd, output, len);
	while (parser->width-- > len + sign)
		*ret += write(parser->fd, &wchar, 1);
}

int	printsignedint(t_parse *parser)
{
	int			ret;
	int			sign;
	char		*output;
	char		wchar;

	wchar = getwchar(parser);
	ret = 0;
	output = get_num(parser, &sign);
	if (parser->plus && !sign && parser->width <= (int)ft_strlen(output))
		output = ft_safejoin("+", output);
	if (sign && wchar == '0')
		ret += write (1, "-", 1);
	if (!parser->negative_width)
		negativecase(parser, &ret, sign, output);
	else
		normalcase(parser, &ret, sign, output);
	free(output);
	return (ret);
}
