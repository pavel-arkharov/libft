/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:45 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (src >= dst)
	{
		while (len > i++)
			*pdst++ = *psrc++;
	}
	else if (src < dst)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	return (dst);
}
