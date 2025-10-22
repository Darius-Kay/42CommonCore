/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:44 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 14:49:27 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrsize_hexa(unsigned long long nbr)
{
	int	len;

	len = 1;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
