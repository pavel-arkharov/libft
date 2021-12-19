/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:29:07 by parkharo          #+#    #+#             */
/*   Updated: 2021/11/19 16:32:54 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnode(t_list	*lst)
{
	if (lst)
		ft_putendl((char *)lst->content);
	else
		ft_putendl("The node is empty");
}
