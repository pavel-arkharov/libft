/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:52:38 by parkharo          #+#    #+#             */
/*   Updated: 2021/12/26 20:58:36 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*ptr;

	while (*stringp)
	{
		ptr = (char *)delim;
		while (ptr)
		{
			if (*ptr == **stringp)
			{
				**stringp = '\0';
				return ((*stringp) + 1);
			}
			ptr += 1;
		}
		*stringp += 1;
	}
	return (NULL);
}
