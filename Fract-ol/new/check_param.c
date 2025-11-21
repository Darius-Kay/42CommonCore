/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:20:38 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 13:40:30 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_first_param(char *av1)
{
	char	*mandelbrot;
	char	*julia;

	mandelbrot = "mandelbrot";
	julia = "julia";
	if ((ft_strcmp(av1, mandelbrot)) && (ft_strcmp(av1, julia)))
		return (1);
	else
		return (0);
}
