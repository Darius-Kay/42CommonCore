/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 03:01:51 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/18 05:04:16 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		size;
	long	long_n;

	long_n = (long)n;
	size = ft_nb_len(n);
	nbr = (char *)ft_calloc(size + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	if (long_n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		long_n = -long_n;
	}
	while (long_n > 0)
	{
		nbr[--size] = (long_n % 10) + '0';
		long_n = long_n / 10;
	}
	return (nbr);
}
