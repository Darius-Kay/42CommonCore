/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 06:05:24 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/22 14:54:05 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_conversion(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_len((char)va_arg(args, int), 1);
	else if (c == 's')
		count = ft_putstr_len(va_arg(args, char *), 1);
	else if (c == 'p')
		count = ft_putp(va_arg((args), void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_len(va_arg((args), int), 1);
	else if (c == 'u')
		count = ft_putunbr(va_arg((args), unsigned int));
	else if (c == 'x')
		count = ft_putnbr_hexa((va_arg((args), unsigned int)), 1);
	else if (c == 'X')
		count = ft_putnbr_hexa((va_arg((args), unsigned int)), 2);
	else if (c == '%')
		count = ft_putchar_len('%', 1);
	return (count);
}

static int	is_conversion(char c, char *conv)
{
	char	conversion[10];
	int		i;

	ft_strlcpy(conversion, "cspdiuxX%", 10);
	i = 0;
	while (i < 9)
	{
		if (conversion[i] == c)
		{
			*conv = conversion[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	char	conv;
	int		i;

	i = 0;
	len = 0;
	conv = '\0';
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_conversion(format[i + 1], &conv))
		{
			len = len + ft_conversion(args, conv);
			i++;
		}
		else
			len = len + ft_putchar_len(format[i], 1);
		i++;
	}
	return (len);
}
