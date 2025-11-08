/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystatus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:31:50 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/08 02:31:50 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_up(int key, void *param)
{
	((t_mlx *)param)->keytab[key] = 0;
}

void	key_down(int key, void *param)
{
	((t_mlx *)param)->keytab[key] = 1;
}
