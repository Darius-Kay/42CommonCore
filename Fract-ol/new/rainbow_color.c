/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:36:10 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/20 09:12:01 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_color	ft_colorchose(t_mlx *mlx)
{
	mlx_color		color;
	static int		choice = 0;

	color = mlx->color.rainbow;	
	if (choice < 255)
	{
		color.r = 255;
		color.g = choice;
		color.b = 0;
	}
	else if (choice < 510)
	{
		color.r = 510 - choice;
		color.g = 255;
		color.b = 0;
	}
	else if (choice < 765)
	{
		color.r = 0;
		color.g = 255;
		color.b = choice - 510;
	}
	else if (choice < 1020)
	{
		color.r = 0;
		color.g = 1020 - choice;
		color.b = 255;
	}
	else if (choice < 1275)
	{
		color.r = choice - 1020;
		color.g = 0;
		color.b = 255;
	}
	else if (choice < 1530)
	{
		color.r = 255;
		color.g = 0;
		color.b = 1530 - choice;
	}
	else
		choice = 0;
	choice++;
	mlx->color.rainbow = color;
	return (color);
}
