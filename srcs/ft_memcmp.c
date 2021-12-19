/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:41:29 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/17 19:29:00 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)s1 != *(unsigned char *)s2))
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
	}
	return (0);
}
