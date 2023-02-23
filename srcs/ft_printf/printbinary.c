/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:23:14 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/23 09:40:47 by parkharo         ###   ########.fr       */
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

int	printbinary(t_parse *parser)
{
	int			ret;
	char		*output;
	uintmax_t	num;

	ret = 0;
	get_typecasted(parser, &num);
	if (num == 0 && parser->precision == 0)
		output = ft_strdup("");
	else
		output = ft_luitoa_base(num, 2);
	if (parser->hash)
		output = ft_safejoin("0b", output);
	if (!parser->negative_width)
		while (parser->width-- > (int)ft_strlen(output))
			ret += write(parser->fd, " ", 1);
	write(parser->fd, output, ft_strlen(output));
	while (parser->width-- > (int)ft_strlen(output))
			ret += write(parser->fd, " ", 1);
	free(output);
	return (ret);
}
