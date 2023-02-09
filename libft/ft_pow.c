/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:41:25 by parkharo          #+#    #+#             */
/*   Updated: 2022/09/27 18:43:51 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_pow(int nbr, int power)
{
	long	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power--)
	{
		result *= nbr;
	}
	return (result);
}
