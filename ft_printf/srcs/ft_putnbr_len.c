/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:20:12 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 14:58:26 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_to_fd(long long int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_len("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_to_fd(-n, fd);
		return ;
	}
	else if (n >= 10)
	{
		ft_putnbr_to_fd(n / 10, fd);
		ft_putnbr_to_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

int	ft_putnbr_len(int n, int fd)
{
	int				len;

	len = 0;
	len = ft_nbrsize(n);
	if (n < 0)
		len++;
	ft_putnbr_to_fd(n, fd);
	return (len);
}
