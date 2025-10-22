/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:15:57 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 14:52:30 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	phexa(unsigned long long nbr, char *base, unsigned int size)
{
	if (nbr >= size)
	{
		phexa(nbr / size, base, size);
		phexa(nbr % size, base, size);
	}
	else
		write(1, &base[nbr], 1);
}

int	ft_putnbr_hexa(unsigned long long nbr, int choice)
{
	int	nbr_len;

	nbr_len = ft_nbrsize_hexa(nbr);
	if (nbr < 0)
		nbr_len++;
	if (choice == 1)
		phexa(nbr, "0123456789abcdef", 16);
	else
		phexa(nbr, "0123456789ABCDEF", 16);
	return (nbr_len);
}
