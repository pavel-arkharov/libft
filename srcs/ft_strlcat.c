/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:58:24 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/12 18:18:27 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	if (!dst && !src)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len > dstsize)
		return (src_len + dstsize);
	else
	{
		dst += dest_len;
		ft_strlcpy(dst, src, dstsize - dest_len);
		return (dest_len + src_len);
	}
}
