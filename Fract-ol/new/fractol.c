/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:43:26 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 13:24:26 by dakaymak         ###   ########.fr       */
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
		mlx->fr(mlx, *mlx, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	}
}

static void	update_key(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->keytab[KEY_ESC])
		mlx_loop_end(mlx->mlx);
	fractol_choice(mlx);
	update_moving(mlx);
	update_precision(mlx);
	update_color(mlx);
}

static void ft_loop(t_mlx mlx)
{
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, closing_window, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, ft_zoom, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_down, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYUP, key_up, &mlx);
	mlx_add_loop_hook(mlx.mlx, update_key, &mlx);
	mlx_add_loop_hook(mlx.mlx, update_paint, &mlx);
	mlx_loop(mlx.mlx);
	ft_cleaning_mlx(&mlx);
	free(mlx.keytab);
}

int	main(int ac, char *av[])
{
	t_mlx	mlx;

	if (ac > 4)
		return (too_much_param());
	mlx = ft_init_tmlx();
	if (mlx.error == true)
	{
		if (mlx.mlx != MLX_NULL_HANDLE)
			ft_cleaning_mlx(&mlx);
		return (-1);
	}
	if (check_first_param(av[1]))
		return (too_much_param());
	ft_loop(mlx);
	return (0);
}
