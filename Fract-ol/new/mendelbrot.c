/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 03:58:25 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 08:09:31 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_frac(t_mlx mlx, double c_rx, double c_iy, double tmp)
{
	double	z_r;
	double	z_i;
	double	z_r2;
	double	z_i2;
	int		i;

	z_r = 0.0;
	z_i = 0.0;
	i = 0;
	while (i < mlx.coord.imax)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 >= 4.0)
			break ;
		tmp = z_r;
		z_r = (z_r2 - z_i2 + c_rx);
		z_i = (2.0 * tmp * z_i + c_iy);
		i++;
	}
	return (i);
}

void	mendelbrot(t_mlx *pmlx, t_mlx mlx, double x, double y)
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
			frac_calc = is_in_frac(mlx, (x / (mlx.coord.zoom) + mlx.coord.offx),
					-(y / (mlx.coord.zoom) + (mlx.coord.offy)), 0.0);
			if (frac_calc == mlx.coord.imax)
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y, mlx.color.inside);
			else if (frac_calc <= 20)
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
