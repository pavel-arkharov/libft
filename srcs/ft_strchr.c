/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:39:18 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/04 19:56:20 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		ch;
	char		*ptr;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == ch)
			return (ptr);
		ptr += 1;
	}
	if (ch == '\0')
		return (ptr);
	return (NULL);
}
