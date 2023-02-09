/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:16:53 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/13 17:12:37 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*map;
	char	*ptr;

	if (!s)
		return (NULL);
	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	ptr = map;
	while (*s)
		*map++ = f(*s++);
	return (ptr);
}
