/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kleinian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:28:46 by dakaymak          #+#    #+#             */
/*   Updated: 2025/11/25 11:36:52 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kleinian.h"

static double	mobius_transformation(t_mobius mobius, double z)
{
	double	res;

	res = ((mobius.a * z) + mobius.b) / ((mobius.c * z) + mobius.d);
	return (res);
}
