/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:42:13 by parkharo          #+#    #+#             */
/*   Updated: 2022/03/16 08:50:34 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
* USAGE: Converts from decimal to base in range 2-36
*/

static char	*converter(char *res, long num, int base, int length)
{
	while (num >= base)
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

char	*ft_itoa_base(long num, int base)
{
	size_t	length;
	long	tmp;
	char	*res;

	if (base > 36 || base < 2)
		return (NULL);
	length = 1;
	if (num < 0)
	{
		tmp = -num;
		length++;
	}
	else
		tmp = num;
	while (tmp >= base && ++length)
		tmp /= base;
	res = (char *)malloc(sizeof(char) * length + 1);
	res[length] = '\0';
	return (res = converter(res, num, base, length));
}
