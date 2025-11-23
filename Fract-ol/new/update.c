/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:43:33 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/23 15:15:02 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "fractol.h"

void	update_color(t_mlx *mlx)
{
	mlx_color	old_outl;

	old_outl = mlx->color.outl;
	if (mlx->keytab[KEY_1])
		mlx->color.outl = color_change(mlx, RED);
	if (mlx->keytab[KEY_2])
		mlx->color.outl = color_change(mlx, YELLOW);
	if (mlx->keytab[KEY_3])
		mlx->color.outl = color_change(mlx, GREEN);
	if (mlx->keytab[KEY_4])
		mlx->color.outl = color_change(mlx, CYAN);
	if (mlx->keytab[KEY_5])
		mlx->color.outl = color_change(mlx, BLUE);
	if (mlx->keytab[KEY_6])
		mlx->color.outl = color_change(mlx, MAGENTA);
	if (mlx->keytab[KEY_7])
		mlx->color.outl = color_change(mlx, WHITE);
	if (mlx->keytab[KEY_8] || mlx->is_rainbow)
		color_switch(&(mlx->color), mlx, 1);
	if (mlx->keytab[KEY_9])
		color_switch(&(mlx->color), mlx, 2);
	if (old_outl.rgba != mlx->color.outl.rgba)
		mlx->update = true;
}

void	update_moving(t_mlx *mlx)
{
	double	tmp_x;
	double	tmp_y;

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

void	update_precision(t_mlx *mlx)
{
	int		old_imax;

	old_imax = mlx->coord.imax;
	if (mlx->keytab[KEY_E])
		mlx->coord.imax = mlx->coord.imax + 10;
	if (mlx->keytab[KEY_R])
		mlx->coord.imax = mlx->coord.imax - 10 * (mlx->coord.imax > 0);
	if (old_imax != mlx->coord.imax)
		mlx->update = true;
}

void	ft_zoom(int button, void *param)
{
	t_mlx	*mlx;
	int		mouse_x;
	int		mouse_y;
	double	zoom_factor;

	mlx = (t_mlx *)param;
	mlx_mouse_get_pos(mlx->mlx, &mouse_x, &mouse_y);
	zoom_factor = 1.5;
	if (button == 1)
	{
		mlx->coord.offx = ((double)mouse_x / mlx->coord.zoom + mlx->coord.offx)
			- ((double)mouse_x / (mlx->coord.zoom * zoom_factor));
		mlx->coord.offy = ((double)mouse_y / mlx->coord.zoom + mlx->coord.offy)
			- ((double)mouse_y / (mlx->coord.zoom * zoom_factor));
		mlx->coord.zoom = mlx->coord.zoom * zoom_factor;
	}
	if (button == 2)
	{
		mlx->coord.offx = ((double)mouse_x / mlx->coord.zoom + mlx->coord.offx)
			- ((double)mouse_x / (mlx->coord.zoom / zoom_factor));
		mlx->coord.offy = ((double)mouse_y / mlx->coord.zoom + mlx->coord.offy)
			- ((double)mouse_y / (mlx->coord.zoom / zoom_factor));
		mlx->coord.zoom = mlx->coord.zoom / zoom_factor;
	}
	mlx->update = true;
}
