/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:03:01 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/16 18:57:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_safejoin(char *s1, char *s2)
{
	char	*sum;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!sum)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		sum[i] = s1[i];
		++i;
	}
	while (s2[j])
		sum[i++] = s2[j++];
	free(s2);
	return (sum);
}

int	writechar(t_parse *parser, char c)
{
	--parser->width;
	return (write(parser->fd, &c, 1));
}

int	find_specifier(char c)
{
	return (c == 'c' || c == 'u' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == '%' || c == 'f'
		|| c == 'x' || c == 'X' || c == 'o' || c == 'b');
}

char	getwchar(t_parse *parser)
{
	if (parser->zero_padding && parser->precision == -1
		&& !parser->negative_width)
		return ('0');
	else
		return (' ');
}

void	add_one(char **str)
{
	int	i;

	i = 0;
	while (!ft_isdigit((*str)[i]))
		++i;
	(*str) = ft_safejoin("1", (*str));
}
