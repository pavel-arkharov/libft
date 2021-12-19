/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:05:56 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/16 17:07:31 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = ft_strnew(n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		ptr[i] = s1[i];
		++i;
	}
	return (ptr);
}
