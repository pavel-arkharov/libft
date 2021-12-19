/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:56:21 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/10 21:37:06 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptr;
	char	*ptr2;

	ptr = s1;
	ptr2 = (char *)s2;
	ptr += ft_strlen(s1);
	while (*ptr2)
		*ptr++ = *ptr2++;
	*ptr = '\0';
	return (s1);
}
