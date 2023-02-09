/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:56:59 by parkharo          #+#    #+#             */
/*   Updated: 2021/12/27 15:01:46 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrsep(char **stringp, int ch)
{
	char	*ptr;

	ptr = ft_strchr(*stringp, ch);
	if (ptr)
	{
		*ptr = '\0';
		ptr++;
	}
	return (ptr);
}
