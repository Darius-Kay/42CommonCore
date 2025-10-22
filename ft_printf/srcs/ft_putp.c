/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:50:46 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 15:04:39 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		len = 5;
	}
	else
	{
		len = len + 2;
		write(1, "0x", 2);
		len = len + ft_putnbr_hexa((unsigned long long)ptr, 1);
	}
	return (len);
}
