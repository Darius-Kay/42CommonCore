/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 07:50:40 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 16:29:48 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_frac(t_mlx mlx, double c_rx, double c_iy, t_julia	julia)
{
	double	z_r;
	double	z_i;
	double	z_r2;
	double	z_i2;
	int		i;

	z_r = c_rx;
	z_i = c_iy;
	i = 0;
	while (i < mlx.coord.imax)
	{
		z_r2 = z_r * z_r;
		z_i2 = z_i * z_i;
		if (z_r2 + z_i2 >= 4.0)
			break ;
		julia.oldzr = z_r;
		z_r = (z_r2 - z_i2 + julia.julia_x);
		z_i = (2.0 * julia.oldzr * z_i + julia.julia_y);
		i++;
	}
	return (i);
}

void	julia(t_mlx *pmlx, t_mlx mlx, double x, double y)
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
					-(y / (mlx.coord.zoom) + (mlx.coord.offy)), mlx.julia);
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
