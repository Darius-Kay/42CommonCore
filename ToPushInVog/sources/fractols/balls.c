/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:11:45 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/25 12:07:23 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_ball(t_mlx mlx, double c_r, double c_i)
{
	double	z_r;
	double	z_i;
	double	mag_sq;
	double	temp;
	int		i;

	z_r = c_r;
	z_i = c_i;
	i = 0;
	while (i < mlx.coord.imax)
	{
		mag_sq = z_r * z_r + z_i * z_i;
		if (mag_sq > 10.0)
			break ;
		if (mag_sq < 0.01)
			return (i);
		temp = 1.0 / mag_sq;
		z_r = z_r * temp + 1.0;
		z_i = z_i * temp;
		i++;
	}
	return (mlx.coord.imax);
}

void	balls(t_mlx *pmlx, t_mlx mlx, double x, double y)
{
	int			frac_calc;
	mlx_color	mask;
	mlx_color	outl_color;

	mask.rgba = 0xF0F0F0FF;
	outl_color = mlx.color.outl;
	while (x < mlx.info.width)
	{
		y = 0.0;
		while (y < mlx.info.height)
		{
			frac_calc = is_in_ball(mlx, (x / (mlx.coord.zoom) + mlx.coord.offx),
					-(y / (mlx.coord.zoom) + mlx.coord.offy));
			if (frac_calc == mlx.coord.imax)
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y, mlx.color.inside);
			else if (frac_calc <= 5)
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y, mlx.color.bg);
			else
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y,
					(mlx_color)(frac_calc * (outl_color.rgba & mask.rgba)));
			y = y + 1.0;
		}
		x = x + 1.0;
	}
	pmlx->update = false;
}
