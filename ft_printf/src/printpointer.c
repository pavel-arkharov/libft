/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:15:44 by parkharo          #+#    #+#             */
/*   Updated: 2023/01/24 00:03:38 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifcase(char **output, size_t *len)
{
		(*output) = ft_safejoin("0x", (*output));
		*len = ft_strlen((*output));
}

int	elsecase(char *output, size_t *len, t_parse *parser)
{
	*len = ft_strlen(output) + 2;
	return (write(parser->fd, "0x", 2));
}

int	printpointer(t_parse *parser)
{
	size_t	len;
	int		ret;
	long	ptr;
	char	*output;

	ret = 0;
	ptr = va_arg(parser->args, long);
	if (ptr == 0 && parser->precision == 0)
		output = ft_strdup("");
	else
		output = ft_itoa_base(ptr, 16);
	if ((int)ft_strlen(output) >= parser->precision)
		ifcase(&output, &len);
	else
		ret += elsecase(output, &len, parser);
	if (!parser->negative_width)
		while ((int)len < parser->width--)
			ret += write (1, " ", 1);
	while (parser->precision-- > (int)len - 2)
		ret += write(parser->fd, "0", 1);
	ret += write (1, output, ft_strlen(output));
	while ((int)len < parser->width--)
			ret += write (1, " ", 1);
	free(output);
	return (ret);
}
