/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:14:25 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lsttail(t_list **lst)
{
	if (lst)
	{
		while ((*lst)->next->content)
			(*lst) = (*lst)->next;
		(*lst)->next = NULL;
	}
}
