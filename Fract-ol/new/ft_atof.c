/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:20:56 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 16:21:52 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_power(double x, int power)
{
	double	res;

	res = 1.0;
	while (power > 0)
	{
		res = res * x;
		power--;
	}
	return (res);
}

static double	after_comma(char *str)
{
	double	res;
	int		i;

	res = 0.0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = (res * 10.0) + (str[i] - '0');
		i++;
	}
	res = res / (ft_power(10.0, i));
	return (res);
}

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;

	res = 0.0;
	i = 0;
	sign = 1;
	if (!str)
		return (-1);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10.0) + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
		res = res + after_comma(str + i + 1);
	return (res * sign);
}
