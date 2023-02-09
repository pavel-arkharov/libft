/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:55:22 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/12 20:01:42 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_printable(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_isprint(*s++))
			return (0);
	return (1);
}
