/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:52:38 by parkharo          #+#    #+#             */
/*   Updated: 2021/12/26 21:46:09 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*ptr;
	size_t	i;
	//size_t	j;

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
