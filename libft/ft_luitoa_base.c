/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:00:16 by parkharo          #+#    #+#             */
/*   Updated: 2022/03/16 08:51:47 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*converter(char *res, uintmax_t num, int base, int length)
{
	while (num >= (unsigned long)base)
	{
		if (num % base < 10)
			res[--length] = '0' + (num % base);
		else
			res[--length] = 87 + (num % base);
		num /= base;
	}
	if (num < 10)
		res[--length] = '0' + num;
	else
		res[--length] = 87 + num;
	return (res);
}

char	*ft_luitoa_base(uintmax_t num, int base)
{
	size_t		length;
	uintmax_t	tmp;
	char		*res;

	if (base > 36 || base < 2)
		return (NULL);
	length = 1;
	tmp = num;
	while (tmp >= (unsigned long)base && ++length)
		tmp /= base;
	res = (char *)malloc(sizeof(char) * length + 1);
	res[length] = '\0';
	return (res = converter(res, num, base, length));
}
