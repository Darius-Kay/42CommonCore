/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kleinian.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:08:26 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/23 15:16:27 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KLEINIAN_H
# define KLEINIAN_H

typedef struct s_kleinian
{
    double a_r, a_i, b_r, b_i;
    double c_r, c_i, d_r, d_i;
    double a2_r, a2_i, b2_r, b2_i;
    double c2_r, c2_i, d2_r, d2_i;
    double bailout;
} t_kleinian;

typedef struct s_complex
{
    double r;
    double i;
} t_complex;

typedef struct s_mobius_data
{
    t_complex z;
    t_complex a;
    t_complex b;
    t_complex c;
    t_complex d;
} t_mobius_data;

void init_kleinian(t_kleinian *klein);
#endif
