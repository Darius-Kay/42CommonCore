/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:43:33 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/13 21:00:54 by dakaymak         ###   ########.fr       */
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
	if (mlx->keytab[KEY_W] || mlx->keytab[KEY_UP])
		mlx->coord.offy = mlx->coord.offy - (10.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_S] || mlx->keytab[KEY_DOWN])
		mlx->coord.offy = mlx->coord.offy + (10.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_A] || mlx->keytab[KEY_LEFT])
		mlx->coord.offx = mlx->coord.offx - (10.0 / mlx->coord.zoom);
	if (mlx->keytab[KEY_D] || mlx->keytab[KEY_RIGHT])
		mlx->coord.offx = mlx->coord.offx + (10.0 / mlx->coord.zoom);
	if ((tmp_x != mlx->coord.offx) || (tmp_y != mlx->coord.offy))
		mlx->update = true;
}

void	update_precision(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->keytab[KEY_E])
		mlx->coord.imax = mlx->coord.imax + 10;
	if (mlx->keytab[KEY_R])
		mlx->coord.imax = mlx->coord.imax - 10 * (mlx->coord.imax > 0);
	if (mlx->keytab[KEY_1])
		mlx->color.outl.rgba = RED;
	if (mlx->keytab[KEY_2])
		mlx->color.outl.rgba = YELLOW;
	if (mlx->keytab[KEY_3])
		mlx->color.outl.rgba = GREEN;
	if (mlx->keytab[KEY_4])
		mlx->color.outl.rgba = CYAN;
	if (mlx->keytab[KEY_5])
		mlx->color.outl.rgba = BLUE;
	if (mlx->keytab[KEY_6])
		mlx->color.outl.rgba = MAGENTA;
	if (mlx->keytab[KEY_7])
		mlx->color.outl.rgba = WHITE;
	mlx->update = true;
}

void	ft_zoom(int button, void *param)
{
	t_mlx	*mlx;
	double	half_height;
	double	half_width;

	mlx = (t_mlx *)param;
	half_height = (double)(((double)mlx->info.height) / 2.0);
	half_width = (double)(((double)mlx->info.width) / 2.0);
	if (button == 1)
	{
		mlx->coord.offx = (half_width / mlx->coord.zoom + mlx->coord.offx)
			- (half_width / (mlx->coord.zoom * 1.5));
		mlx->coord.offy = (half_height / mlx->coord.zoom + mlx->coord.offy)
			- (half_height / (mlx->coord.zoom * 1.5));
		mlx->coord.zoom = mlx->coord.zoom * 1.5;
	}
	if (button == 2)
	{
		mlx->coord.offx = (half_width / mlx->coord.zoom + mlx->coord.offx)
			- (half_width / (mlx->coord.zoom / 1.5));
		mlx->coord.offy = (half_height / mlx->coord.zoom + mlx->coord.offy)
			- (half_height / (mlx->coord.zoom / 1.5));
		mlx->coord.zoom = mlx->coord.zoom / 1.5;
	}
	mlx->update = true;
}
