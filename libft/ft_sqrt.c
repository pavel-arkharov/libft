/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:43:07 by parkharo          #+#    #+#             */
/*   Updated: 2022/09/20 21:43:12 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_sqrt(long nbr)
{
	unsigned long	result;

	if (nbr <= 0)
	{
		return (0);
	}
	result = 1;
	while (result * result < (unsigned long)nbr)
		result++;
	return (result);
}
