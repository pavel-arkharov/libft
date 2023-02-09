/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:36:23 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:01:44 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	printchar(t_parse *parser)
{
	int		ret;
	char	charac;

	ret = 0;
	charac = va_arg(parser->args, int);
	if (!parser->negative_width)
	{
		while (--parser->width > 0)
			ret += write(parser->fd, " ", 1);
		return (ret += write(parser->fd, &charac, 1));
	}
	else
	{
		ret += write(parser->fd, &charac, 1);
		while (--parser->width > 0)
			ret += write(parser->fd, " ", 1);
	}
	return (ret);
}
