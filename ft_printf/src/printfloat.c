/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:13:34 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:06:24 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	add_float_sign(t_parse *parser, char **str, long double num)
{
	char	*temp;

	temp = NULL;
	if (num < 0)
	{
		temp = ft_strjoin("-", *str);
		free(*str);
		*str = temp;
	}
	else if (num >= 0 && (parser->plus == 1 || parser->space == 1))
	{
		if (parser->plus == 1)
			temp = ft_strjoin("+", *str);
		else if (parser->space == 1)
			temp = ft_strjoin(" ", *str);
		free(*str);
		*str = temp;
	}
}

static	void	round_up(char **str, int i)
{
	if ((*str)[i] == '.')
		round_up(str, i - 1);
	else if ((*str)[i] + 1 <= '9')
		(*str)[i] += 1;
	else if ((*str)[i] == '9')
	{
		(*str)[i] = '0';
		if (!(ft_isdigit((*str)[i - 1]) && (*str)[i - 1] != '.'))
			add_one(str);
		round_up(str, i - 1);
	}
}

static	long double	add_float_part(long double num,
								char **float_str, int precision)
{
	int		i;

	*float_str = ft_strnew(310);
	i = 0;
	num -= (long double)(long long)num;
	if (num < 0)
		num = -num;
	if (precision > 0)
	{
		(*float_str)[i] = '.';
		++i;
	}
	while (precision-- > 0)
	{
		num *= (long double) 10.0;
		(*float_str)[i++] = ((long long)num % 10) + '0';
		num -= (long long)num;
	}
	return (num);
}

static	void	ft_ftoa(long double num, int precision, char **str)
{
	size_t		len;
	char		*int_part;
	char		*float_part;
	long double	remainder;

	int_part = ft_uitoa((long long)num);
	remainder = add_float_part(num, &float_part, precision);
	*str = ft_strjoin(int_part, float_part);
	free(int_part);
	free(float_part);
	len = ft_strlen((*str));
	if (1.0 - remainder < 0 + remainder || (1.0 - remainder == 0 + remainder
			&& ((*str)[ft_strlen((*str)) - 1] + 1 - '0') % 2 == 0))
		round_up(str, len - 1);
}

int	printfloat(t_parse *parser)
{
	int			ret;
	long double	num;
	char		*str;
	int			prec;
	long		tail;

	prec = parser->precision;
	ret = 0;
	if (parser->typecast == 5)
		num = (long double)va_arg(parser->args, long double);
	else
		num = (double)va_arg(parser->args, double);
	if (if_nan_inf(num, parser, &str))
		return (handle_nan_inf(parser, &str, &ret));
	handle_big_prec(&(parser->precision), &tail);
	if (parser->precision == -1)
		ft_ftoa(num, 6, &str);
	else
		ft_ftoa(num, parser->precision, &str);
	add_float_sign(parser, &str, num);
	ret += write(parser->fd, str, ft_strlen(str));
	print_dot(parser->hash, prec, &ret, parser);
	print_tail(tail, &ret, parser);
	free(str);
	return (ret);
}
