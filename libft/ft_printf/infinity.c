/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:28:01 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/16 18:57:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	if_nan_inf(long double arg, t_parse *parser, char **str)
{
	if (arg != arg)
	{
		*str = ft_strdup("nan");
		parser->zero_padding = 0;
		parser->precision = 0;
		return (1);
	}
	if (arg == 1.0 / 0.0)
	{
		*str = ft_strdup("inf");
		if (parser->plus)
			*str = ft_safejoin("+", *str);
		parser->precision = 0;
		parser->zero_padding = 0;
		return (1);
	}
	if (arg == -1.0 / 0.0)
	{
		*str = ft_strdup("-inf");
		parser->precision = 0;
		parser->zero_padding = 0;
		return (1);
	}
	return (0);
}

int	handle_nan_inf(t_parse *parser, char **str, int *ret)
{
	if (!parser->negative_width)
		while (parser->width-- > (int)ft_strlen(*str))
			*ret += write (1, " ", 1);
	*ret += write (1, (*str), ft_strlen(*str));
	while (parser->width-- > (int)ft_strlen(*str))
			*ret += write (1, " ", 1);
	free((*str));
	return (*ret);
}

void	handle_big_prec(int *precision, long *tail)
{
	*tail = 0;
	if (*precision > 310)
	{
		*tail = *precision - 310;
		*precision = 310;
	}
}

void	print_tail(long tail, int *ret, t_parse *parser)
{
	while (tail--)
		*ret += write(parser->fd, "0", 1);
}

void	print_dot(int hash, int prec, int *ret, t_parse *parser)
{
	if (hash && prec == 0)
		*ret += write(parser->fd, ".", 1);
}
