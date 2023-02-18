/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:07:43 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_uitoa(intmax_t num)
{
	char	*str;
	int		len;

	len = ft_countdigits(num);
	str = ft_strnew(len);
	if (num < 0)
	{
		if (num == INT64_MIN)
		{
			str[0] = '9';
			num = -223372036854775808;
		}
		num = -num;
	}
	while (num >= 10)
	{
		str[len-- - 1] = '0' + (num % 10);
		num /= 10;
	}
	str[len - 1] = '0' + num;
	return (str);
}
