/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 22:10:45 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/18 13:29:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_occurence(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (needle[i] != haystack[i])
			return (0);
		++i;
	}
	return (1);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*needle == *haystack && check_occurence(haystack, needle))
			return ((char *)haystack);
		haystack += 1;
	}
	return (0);
}	
