/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:55:28 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:00:33 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_parse	*init_parser(int fd)
{
	t_parse	*parser;

	parser = (t_parse *)malloc(sizeof(t_parse));
	if (!parser)
		return (NULL);
	parser->fd = fd;
	parser->capital = 0;
	parser->hash = 0;
	parser->length = 0;
	parser->negative_width = 0;
	parser->plus = 0;
	parser->precision = -1;
	parser->space = 0;
	parser->width = 0;
	parser->zero_padding = 0;
	parser->typecast = 0;
	return (parser);
}

void	flush_parser(t_parse **parser)
{
	(*parser)->capital = 0;
	(*parser)->hash = 0;
	(*parser)->length = 0;
	(*parser)->negative_width = 0;
	(*parser)->plus = 0;
	(*parser)->precision = -1;
	(*parser)->space = 0;
	(*parser)->width = 0;
	(*parser)->zero_padding = 0;
	(*parser)->typecast = 0;
}

void	parse_width(t_parse **parser, char **str)
{
	char	*tmp;
	char	*width;

	tmp = *str;
	while (ft_isdigit(*tmp))
		tmp += 1;
	width = ft_strsub(*str, 0, (tmp - *str));
	(*parser)->width = ft_atoi(width);
	*str = tmp - 1;
	free(width);
}

void	parse_precision(t_parse **parser, char **str)
{
	char	*tmp;
	char	*prec;

	tmp = *str + 1;
	while (ft_isdigit(*tmp))
		tmp += 1;
	prec = ft_strsub(*str, 1, (tmp - *str));
	(*parser)->precision = ft_atoi(prec);
	free(prec);
	*str = tmp - 1;
	if (*tmp == '*')
	{
		(*parser)->precision = va_arg((*parser)->args, int);
		*str += 1;
		if ((*parser)->precision < 0)
			(*parser)->precision = -1;
	}
}

void	parse_typecast(t_parse **parser, char **str)
{
	if (ft_strncmp(*str, "ll", 2) == 0)
	{
		(*parser)->typecast = 3;
		*str += 1;
	}
	else if (ft_strncmp(*str, "hh", 2) == 0)
	{	
		(*parser)->typecast = 4;
		*str += 1;
	}	
	else if (ft_strncmp(*str, "l", 1) == 0)
		(*parser)->typecast = 1;
	else if (ft_strncmp(*str, "h", 1) == 0)
		(*parser)->typecast = 2;
	else if (ft_strncmp(*str, "L", 1) == 0)
		(*parser)->typecast = 5;
}
