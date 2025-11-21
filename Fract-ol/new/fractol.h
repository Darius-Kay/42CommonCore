/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 02:35:32 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/21 16:28:49 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MacroLibX/includes/mlx.h"
# include "../MacroLibX/includes/mlx_extended.h"
# include <stdlib.h>
# include <math.h>
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
	mlx_color	bg;
	mlx_color	inside;
	mlx_color	rainbow;
}	t_color;

typedef struct s_coord
{
	double		offx;
	double		offy;
	double		zoom;
	int			imax;
}	t_coord;

typedef struct s_julia
{
	double	av_x;
	double	av_y;
	double	julia_x;
	double	julia_y;
	double	oldzr;
}	t_julia;

typedef struct s_mlx
{
	mlx_context				mlx;
	mlx_window				win;
	mlx_image				img;
	t_coord					coord;
	t_color					color;
	t_julia					julia;
	mlx_window_create_info	info;
	int						*keytab;
	bool					update;
	bool					is_rainbow;
	bool					error;
	void					(*fr)(struct s_mlx *, struct s_mlx, double, double);
}	t_mlx;

typedef struct s_oldjulia
{
	double	old_x;
	double	old_y;
	void	(*old_fr)(t_mlx *, t_mlx, double, double);
}	t_oldjulia;

t_mlx		ft_init_tmlx(void);
// Utils functions
int			ft_isnumber(char c);
int			ft_iscomma(char c);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strcmp(char *s1, char *s2);
double		ft_atof(char *str);
// Key related function
void		key_up(int key, void *param);
void		key_down(int key, void *param);
void		update_precision(t_mlx *mlx);
void		update_moving(t_mlx *mlx);
void		update_color(t_mlx *mlx);
void		ft_zoom(int button, void *param);
//Error management and parsing function
void		ft_cleaning_mlx(t_mlx *mlx);
int			display_param(void);
int			check_julia_param(char *av2, char *av3);
int			check_first_param(char *av1);
int			fractol_param(char *av[], t_mlx *mlx);
//Fractol related function
void		fractol_choice(void	*param);
void		julia(t_mlx *pmlx, t_mlx mlx, double x, double y);
void		julia_def_param(t_julia *julia, double x, double y);
void		mendelbrot(t_mlx *pmlx, t_mlx mlx, double x, double y);
//Color related function
void		color_switch(t_color *color, t_mlx *mlx, int choice);
mlx_color	color_change(t_mlx *mlx, int rgba);
#endif
