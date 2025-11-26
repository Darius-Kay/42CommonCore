/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 05:28:04 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/25 12:06:05 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	ft_cleaning_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}

int	display_param(void)
{
	write(1, "mandelbrot\n", 11);
	write(1, "julia, (double)x, (double)y\n", 28);
	write(1, "balls\n", 6);
	return (-2);
}

int	check_first_param(char *av1)
{
	if ((ft_strcmp(av1, "mandelbrot")) && (ft_strcmp(av1, "julia"))
		&& (ft_strcmp(av1, "balls")))
		return (1);
	else
		return (0);
}

int	check_julia_param(char *av2, char *av3)
{
	int	i;

	i = -1;
	while (av2 && av2[++i])
		if (ft_isnumber(av2[i]) && ft_iscomma(av2[i]) && av2[i] != '-')
			return (1);
	i = -1;
	while (av3 && av3[++i])
		if (ft_isnumber(av3[i]) && ft_iscomma(av3[i]) && av3[i] != '-')
			return (1);
	return (0);
}
