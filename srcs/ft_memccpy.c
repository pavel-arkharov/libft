/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:16:13 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		*ptr2;
	unsigned char		ch;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*ptr2 == ch)
		{
			*ptr++ = *ptr2++;
			return ((void *)ptr);
		}
		*ptr++ = *ptr2++;
	}
	return (NULL);
}
