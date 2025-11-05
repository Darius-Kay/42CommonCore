/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:09:43 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/05 12:09:43 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MacroLibX/includes/mlx_extended.h"
#include "MacroLibX/includes/mlx.h"

int main(void)
{
    mlx_context mlx = mlx_init();

    mlx_window_create_info window_info = { 0 };
    window_info.title = "Hello World!";
    window_info.width = 1000;
    window_info.height = 400;
    mlx_window win = mlx_new_window(mlx, &window_info);
	int img_width;
    int img_height;
    mlx_image target = mlx_new_image_from_file(mlx, "/home/dakaymak/Pictures/Wallpapers/aie.png", &img_width, &img_height);
	mlx_put_transformed_image_to_window(mlx, win, target, 0, 0, 1.0f, 0.25f, 0.0f);
	
	mlx_loop(mlx);
    mlx_destroy_image(mlx, target);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
}
