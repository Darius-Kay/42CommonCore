/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:25:29 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 15:04:08 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_print(unsigned long int unbr)
{
	char	c;

	if (unbr >= 10)
	{
		ft_putunbr_print(unbr / 10);
		ft_putunbr_print(unbr % 10);
	}
	else
	{
		c = unbr + '0';
		write(1, &c, 1);
	}
}

int	ft_putunbr(unsigned long int unbr)
{
	int	len;

	len = ft_nbrsize(unbr);
	ft_putunbr_print(unbr);
	return (len);
}
