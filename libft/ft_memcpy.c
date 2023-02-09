/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:42:12 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/27 16:22:13 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d1;

	d1 = dst;
	if (dst == src || n == 0)
		return (d1);
	while (n >= sizeof(long))
	{
		*(long *) d1 = *(const long *) src;
		d1 += sizeof(long);
		src += sizeof(long);
		n -= sizeof(long);
	}
	if (n >= sizeof(int))
	{
		*(int *) d1 = *(const int *) src;
		d1 += sizeof(int);
		src += sizeof(int);
		n -= sizeof(int);
	}
	while (n-- > 0)
		*(char *) d1++ = *(const char *) src++;
	return (dst);
}
