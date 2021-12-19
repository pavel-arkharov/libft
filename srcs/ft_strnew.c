/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:19:34 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/17 19:04:48 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (i < size + 1)
		ptr[i++] = '\0';
	return (ptr);
}
