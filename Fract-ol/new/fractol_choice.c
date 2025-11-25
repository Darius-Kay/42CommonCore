/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 04:24:56 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/25 12:00:01 by dakaymak         ###   ########.fr       */
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
	if (mlx->keytab[KEY_FOUR])
		julia_def_param(&(mlx->julia), mlx->julia.av_x, mlx->julia.av_y);
	if (mlx->keytab[KEY_FIVE])
		mlx->fr = balls;
	if ((old_julia.old_x != mlx->julia.julia_x)
		|| (old_julia.old_y == mlx->julia.julia_y)
		|| (old_julia.old_fr != mlx->fr))
		mlx->update = true;
}

int	fractol_param(char *av[], t_mlx *mlx)
{
	if (!(ft_strcmp(av[1], "mandelbrot")))
		return (0);
	else if (!(ft_strcmp(av[1], "balls")))
		mlx->fr = balls;
	else if (!(ft_strcmp(av[1], "julia")))
	{
		mlx->fr = julia;
		if (check_julia_param(av[2], av[3]))
			return (1);
		if (av[2] && av[3])
		{
			mlx->julia.av_x = ft_atof(av[2]);
			mlx->julia.av_y = ft_atof(av[3]);
			julia_def_param(&(mlx->julia), mlx->julia.av_x, mlx->julia.av_y);
		}
		else
		{
			mlx->julia.julia_x = 0.0;
			mlx->julia.julia_y = 0.0;
		}
	}
	return (0);
}
