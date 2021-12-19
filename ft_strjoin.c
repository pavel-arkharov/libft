/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:32:50 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/13 17:10:11 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*sum;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!sum)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		sum[i] = s1[i];
		++i;
	}
	while (s2[j])
		sum[i++] = s2[j++];
	return (sum);
}
