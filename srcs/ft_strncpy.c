/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:58:45 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/02 13:11:32 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (*src && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	while (len-- > 0)
		*dst++ = '\0';
	return (ptr);
}
