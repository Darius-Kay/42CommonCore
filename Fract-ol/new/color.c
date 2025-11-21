/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:36:10 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 11:13:08 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_switch(t_color *color, t_mlx *mlx, int choice)
{
	if (choice == 1)
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
