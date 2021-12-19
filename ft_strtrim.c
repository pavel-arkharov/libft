/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:45:27 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/17 19:16:10 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static	size_t	get_start(char *s1)
{
	size_t	i;

	i = 0;
	while (ft_is_ws(s1[i]))
		i++;
	return (i);
}

static	size_t	get_end(char *s2, size_t len)
{	
	while (ft_is_ws(s2[len - 1]) && len > 0)
		len--;
	return (len);
}

char	*ft_strtrim(const char *s)
{
	char	*trim;
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	start = get_start((char *)s);
	end = get_end((char *)s, len);
	if (end - start == len)
		return (ft_strdup((char *)s));
	if (start - end == len)
		return (ft_strnew(0));
	trim = ft_strnew((end - start) * sizeof(char));
	if (!trim)
		return (NULL);
	ptr = trim;
	while (start != end)
		*trim++ = s[start++];
	return (ptr);
}
