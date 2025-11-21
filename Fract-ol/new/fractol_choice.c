/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 04:24:56 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 13:16:58 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "fractol.h"

void	julia_def_param(t_julia *julia, double x, double y)
{
	julia->julia_x = x;
	julia->julia_y = y;
}

void	fractol_choice(void	*param)
{
	t_mlx		*mlx;
	t_oldjulia	old_julia;

	mlx = (t_mlx *)param;
	old_julia.old_x = mlx->julia.julia_x;
	old_julia.old_y = mlx->julia.julia_y;
	old_julia.old_fr = mlx->fr;
	if (mlx->keytab[KEY_M])
		mlx->fr = mendelbrot;
	if (mlx->keytab[KEY_J]) 
		mlx->fr = julia;
	if (mlx->keytab[KEY_ONE])
		julia_def_param(&(mlx->julia), -0.7, 0.27);
	if (mlx->keytab[KEY_TWO])
		julia_def_param(&(mlx->julia), -0.8, 0.1561);
	if (mlx->keytab[KEY_THREE])
		julia_def_param(&(mlx->julia), 0.355534, -0.337292);
	if ((old_julia.old_x != mlx->julia.julia_x) ||
		(old_julia.old_y = mlx->julia.julia_y) ||
		(old_julia.old_fr != mlx->fr))
		mlx->update = true;
}
