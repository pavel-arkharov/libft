/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:31:18 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	char		*ptr;
	int			i;

	ch = (char)c;
	ptr = (char *)s;
	i = (int)ft_strlen((char *)s);
	ptr += i;
	if (ch == '\0')
		return (ptr);
	while (i-- >= 0)
	{
		if (*ptr == ch)
			return (ptr);
		ptr -= 1;
	}
	return (NULL);
}
