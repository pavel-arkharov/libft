/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:08:34 by parkharo          #+#    #+#             */
/*   Updated: 2022/03/16 08:50:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigits(intmax_t num)
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
