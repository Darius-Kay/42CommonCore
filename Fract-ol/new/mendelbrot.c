/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 03:58:25 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/11 00:42:37 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_frac(t_mlx mlx, double c_rx, double c_iy)
{
	double	tmp;
	double	z_r;
	double	z_i;
	double	z_calc;
	int		i;

	z_r = 0.0;
	z_i = 0.0;
	z_calc = z_r * z_r + z_i * z_i;
	i = 0;
	while ((z_calc < 4) && (i < mlx.coord.imax))
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_rx;
		z_i = (2 * z_i * tmp) + c_iy;
		z_calc = z_r * z_r + z_i * z_i;
		i = i + 1;
	}
	return (i);
}

void	mendelbrot(t_mlx mlx, double x, double y)
{
	int						frac_calc;
	mlx_color				mask;
	mlx_color				color;

	color.rgba = BLACK;
	mask.rgba = 0xF0F0F0F0;
	while (x < mlx.info.width)
	{
		y = 0.0;
		while (y < mlx.info.height)
		{
			frac_calc = is_in_frac(mlx, (x / (mlx.coord.zoom) + mlx.coord.offx),
					-(y / (mlx.coord.zoom) + (mlx.coord.offy)));
			if (frac_calc == mlx.coord.imax)
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y, color);
			else
				mlx_set_image_pixel(mlx.mlx, mlx.img, x, y,
					(mlx_color)(frac_calc * mask.rgba + color.rgba));
			y = y + 1.0;
		}
		x = x + 1.0;
	}
	mlx.update = false;
}
