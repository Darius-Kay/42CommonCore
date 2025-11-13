/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:35:32 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/13 20:59:17 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MacroLibX/includes/mlx.h"
# include "../MacroLibX/includes/mlx_extended.h"
# include <stdlib.h>
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define YELLOW 0xFFFF00FF
# define GREEN 0x00FF00FF
# define CYAN 0x00FFFFFF
# define BLUE 0x0000FFFF
# define MAGENTA 0xFF00FFFF

typedef struct s_color
{
	mlx_color	black;
	mlx_color	white;
	mlx_color	red;
	mlx_color	green;
	mlx_color	blue;
	mlx_color	yellow;
	mlx_color	cyan;
	mlx_color	magenta;
	mlx_color	outl;
}	t_color;

typedef struct s_coord
{
	double		offx;
	double		offy;
	double		zoom;
	int			imax;
}	t_coord;

typedef struct s_mlx
{
	mlx_context				mlx;
	mlx_window				win;
	mlx_image				img;
	t_coord					coord;
	t_color					color;
	mlx_window_create_info	info;
	int						*keytab;
	bool					update;
	bool					error;
}	t_mlx;

void		key_up(int key, void *param);
void		key_down(int key, void *param);
t_mlx		ft_init_tmlx(void);
void		mendelbrot(t_mlx mlx, double x, double y);
void		update_precision(void *param);
void		update_moving(void *param);
void		ft_zoom(int button, void *param);
void		*ft_calloc(size_t nmemb, size_t size);
#endif
