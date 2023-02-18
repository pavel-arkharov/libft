/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:52:38 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (*stringp[i])
	{
		ptr = (char *)delim;
		while (*ptr != '\0')
		{
			if (*ptr == *stringp[i])
			{
				*stringp[i++] = '\0';
				return (&(*stringp[i]));
			}
			ptr++;
		}
		++i;
	}
	return (NULL);
}
