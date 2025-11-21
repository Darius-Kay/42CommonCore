/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystatus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:31:50 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 05:50:21 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "fractol.h"

void	key_up(int key, void *param)
{
	((t_mlx *)param)->keytab[key] = 0;
}

void	key_down(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	((t_mlx *)param)->keytab[key] = 1;
	if (mlx->keytab[KEY_9])
		color_switch(&(mlx->color), mlx);
}
