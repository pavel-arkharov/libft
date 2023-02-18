/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:07:09 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/16 18:57:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

static void	negativecase(t_parse *parser, char *output, int sign, int *ret)
{
	char	wchar;
	int		len;

	len = (int)ft_strlen(output);
	wchar = ' ';
	if (parser->zero_padding && parser->precision == -1)
		wchar = '0';
	while (parser->width-- > len + sign && parser->width
		>= parser->precision + sign)
		*ret += write(parser->fd, &wchar, 1);
	if (sign)
		*ret += write(parser->fd, "-", 1);
	while (parser->precision-- > len)
		*ret += write(parser->fd, "0", 1);
	*ret += write(parser->fd, output, ft_strlen(output));
}

static void	normalcase(t_parse *parser, char *output, int *ret, int sign)
{
	char	wchar;
	int		len;

	len = (int)ft_strlen(output);
	wchar = ' ';
	if (parser->zero_padding && parser->precision == -1)
		wchar = '0';
	if (sign)
			*ret += write(parser->fd, "-", 1);
	while (parser->precision-- > len && parser->width--)
		*ret += write(parser->fd, "0", 1);
	*ret += write(parser->fd, output, ft_strlen(output));
	while (parser->width-- > len + sign)
		*ret += write(parser->fd, &wchar, 1);
}

int	printuint(t_parse *parser)
{
	int				ret;
	int				sign;
	uintmax_t		num;
	char			*output;

	sign = 0;
	ret = 0;
	get_typecasted(parser, &num);
	if (num == 0 && parser->precision == 0)
		output = ft_strdup("");
	else
		output = ft_luitoa(num);
	if (!parser->negative_width)
		negativecase(parser, output, sign, &ret);
	else
		normalcase(parser, output, &ret, sign);
	free(output);
	return (ret);
}
