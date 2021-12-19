/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:07:37 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/12 18:16:33 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
		*ptr++ = *ptr2++;
	return (dst);
}
