/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttemplate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:34:52 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/18 14:06:12 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lsttemplate(const char *data)
{
	t_list	*lst;

	lst = ft_lstnew((void const *)data, ft_strlen(data) + 1);
	if (!lst)
		return (NULL);
	return (lst);
}
