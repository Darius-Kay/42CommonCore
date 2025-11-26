/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kleinian.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:24:43 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/26 09:19:09 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KLEINIAN_H
# define KLEINIAN_H
# include "fractol.h"

typedef struct s_mobius
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	z;
}	t_mobius;

typedef struct s_complex
{
	double	real;
	double	image;
}	t_complex;

typedef struct s_circle
{
	t_complex	center;
	double		radius;
}	t_circle;

#endif
