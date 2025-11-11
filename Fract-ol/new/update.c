/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:43:33 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/11 01:24:51 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "fractol.h"

void	update_moving(void *param)
{
	t_mlx	*mlx;
	double	tmp_x;
	double	tmp_y;

	mlx = (t_mlx *)param;
	tmp_x = mlx->coord.offx;
	tmp_y = mlx->coord.offy;
	if (mlx->keytab[KEY_W])
		mlx->coord.offy = mlx->coord.offy - (8.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_S])
		mlx->coord.offy = mlx->coord.offy + (8.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_A])
		mlx->coord.offx = mlx->coord.offx - (8.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_D])
		mlx->coord.offx = mlx->coord.offx + (8.0 / mlx->coord.zoom);
	if ((tmp_x != mlx->coord.offx) || (tmp_y != mlx->coord.offy))
		mlx->update = true;
}

void	update_precision(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->keytab[KEY_E])
	{
		mlx->coord.imax = mlx->coord.imax + 10;
		mlx->update = true;
	}
	if (mlx->keytab[KEY_R])
	{
		mlx->coord.imax = mlx->coord.imax - 10;
		mlx->update = true;
	}
}

void	ft_zoom(int button, void *param)
{
	t_mlx	*mlx;
	t_coord	coord;
	double	half_height;
	double	half_width;

	mlx = (t_mlx *)param;
	coord = mlx->coord;
	half_height = (double)((mlx->info.height) / 2.0);
	half_width = (double)((mlx->info.width) / 2.0);
	if (button == 1)
	{
		mlx->coord.offx = (half_width / coord.zoom + coord.offx)
			- (half_width / (coord.zoom * 1.5));
		mlx->coord.offy = (half_height / coord.zoom + coord.offy)
			- (half_height / (coord.zoom * 1.5));
		mlx->coord.zoom = mlx->coord.zoom * 1.5;
		mlx->update = true;
	}
	if (button == 2)
	{
		mlx->coord.offx = (half_width / coord.zoom + coord.offx)
			- (half_width / (coord.zoom / 1.5));
		mlx->coord.offy = (half_height / coord.zoom + coord.offy)
			- (half_height / (coord.zoom / 1.5));
		mlx->coord.zoom = mlx->coord.zoom / 1.5;
		mlx->update = true;
	}
}
