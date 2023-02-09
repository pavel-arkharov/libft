/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:36:46 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/25 15:06:56 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		node = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = node;
	}
}
