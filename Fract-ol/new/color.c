/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:36:10 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 08:11:59 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_switch(t_color *color, t_mlx *mlx)
{
	if (color->bg.rgba == WHITE)
	{
		color->bg.rgba = BLACK;
		color->inside.rgba = WHITE;
	}
	else
	{
		color->bg.rgba = WHITE;
		color->inside.rgba = BLACK;
	}
	mlx->update = true;
}

mlx_color	color_change(t_mlx *mlx, int rgba)
{
	mlx_color	new_color;

	new_color.rgba = rgba;
	mlx->is_rainbow = false;
	return (new_color);
}

int	nb_of_zoom(double zoom)
{
	int	i;

	i = 0;
	while (zoom != 300.0)
	{
		zoom = zoom / 1.5;
		i++;
	}
	return (i);
}

mlx_color	rainbow_color(t_mlx *mlx)
{
	mlx_color	new_color;
	int			zoom_nb;

	zoom_nb = nb_of_zoom(mlx->coord.zoom) * 5;
	new_color.rgba = mlx->color.rainbow.rgba;
	mlx->color.outl = mlx->color.rainbow;
	if (new_color.r > 0 && new_color.b <= 0)
	{
		new_color.r = new_color.r - zoom_nb;
		new_color.g = new_color.g + zoom_nb;
	}
	if (new_color.g > 0 && new_color.r <= 0)
	{
		new_color.g = new_color.g - zoom_nb;
		new_color.b = new_color.b + zoom_nb;
	}
	if (new_color.b > 0 && new_color.g <= 0)
	{
		new_color.r = new_color.r + zoom_nb;
		new_color.b = new_color.b - zoom_nb;
	}
	mlx->is_rainbow = true;
	return (new_color);
}
