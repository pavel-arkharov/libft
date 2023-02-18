/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:44:02 by parkharo          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:15 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstprint(t_list	*lst)
{
	if (lst)
	{
		ft_putendl("#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#");
		while (lst)
		{
			ft_putstr("\n\nNode named: ");
			ft_putstr((char *)lst->content);
			ft_putstr("\nNext is : ");
			ft_putnbr((long)lst->next);
			lst = lst->next;
		}
		ft_putendl("\nEnd of the list");
		ft_putendl("#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#");
	}
	else
		ft_putendl("The list is empty");
}
