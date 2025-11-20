/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:43:26 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/20 02:17:22 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "fractol.h"

static void	closing_window(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
}

static void	update_paint(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (mlx->update == true)
	{
		mlx_clear_window(mlx->mlx, mlx->win, mlx->color.black);
		mendelbrot(mlx, *mlx, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	}
}

static void	update_key(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->keytab[KEY_ESC])
		mlx_loop_end(mlx->mlx);
	update_moving(param);
	update_precision(param);
}

int	main(void)
{
	t_mlx	mlx;

	mlx = ft_init_tmlx();
	if (mlx.error == true)
	{
		if (mlx.mlx != MLX_NULL_HANDLE)
			ft_cleaning_mlx(&mlx);
		return (-1);
	}
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, closing_window, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, ft_zoom, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_down, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYUP, key_up, &mlx);
	mlx_add_loop_hook(mlx.mlx, update_key, &mlx);
	mlx_add_loop_hook(mlx.mlx, update_paint, &mlx);
	mlx_loop(mlx.mlx);
	ft_cleaning_mlx(&mlx);
	free(mlx.keytab);
	return (0);
}
