/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:33 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	countdigits(uintmax_t num)
{
	int	digits;

	digits = 1;
	while (num / 10)
	{
		num /= 10;
		++digits;
	}
	return (digits);
}

char	*ft_luitoa(uintmax_t num)
{
	char	*str;
	int		len;

	len = countdigits(num);
	str = ft_strnew(len);
	while (num >= 10)
	{
		str[len-- - 1] = '0' + (num % 10);
		num /= 10;
	}
	str[len - 1] = '0' + num;
	return (str);
}
