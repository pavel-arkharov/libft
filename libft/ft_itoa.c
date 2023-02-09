/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:07:06 by parkharo          #+#    #+#             */
/*   Updated: 2022/03/07 19:14:30 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr <= 0)
		++i;
	while (nbr != 0)
	{
		++i;
		nbr /= 10;
	}
	return (i);
}

char	*ft_itoa(long nbr)
{
	size_t	len;
	char	*str;

	if (nbr == MIN_INT)
		return (str = ft_strdup("-2147483648"));
	len = get_len(nbr);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		--len;
	}
	return (str);
}
