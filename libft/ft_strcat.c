/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:56:21 by parkharo          #+#    #+#             */
/*   Updated: 2022/09/19 19:56:19 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptrs1;

	ptrs1 = s1;
	while (*ptrs1)
		ptrs1++;
	ptrs1 = ft_strcpy(ptrs1, s2);
	return (s1);
}
