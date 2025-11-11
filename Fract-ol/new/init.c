/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:48:44 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/11 00:47:15 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static mlx_window_create_info	ft_init_info(void)
{
	mlx_window_create_info	info;

	info.height = 500;
	info.width = 500;
	info.is_fullscreen = false;
	info.is_resizable = false;
	info.title = "Fractroll";
	info.render_target = 0;
	return (info);
}

static t_coord	ft_init_coord(void)
{
	t_coord	coord;

	coord.offx = -1.5;
	coord.offy = -0.9;
	coord.zoom = 300;
	coord.imax = 100;
	return (coord);
}

t_mlx	ft_init_tmlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == MLX_NULL_HANDLE)
	{
		mlx.error = true;
		return (mlx);
	}
	mlx.info = ft_init_info();
	mlx.win = mlx_new_window(mlx.mlx, &(mlx.info));
	mlx.coord = ft_init_coord();
	mlx.img = mlx_new_image(mlx.mlx, mlx.info.width, mlx.info.width);
	mlx.update = true;
	mlx.error = false;
	mlx.keytab = (int *)ft_calloc(255, sizeof(int));
	if (!mlx.keytab)
		mlx.error = true;
	return (mlx);
}
