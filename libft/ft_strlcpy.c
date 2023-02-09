/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:57 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/23 19:31:22 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	src_size = ft_strlen((char *)src);
	if (dstsize != 0)
	{
		while (*src != '\0' && i < dstsize - 1)
		{
			*dst++ = *src++;
			i++;
		}
		*dst++ = '\0';
	}
	return (src_size);
}
