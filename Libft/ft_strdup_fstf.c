/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_fstf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:25:56 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/18 07:11:44 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_fstf(char *src, int start, int finish)
{
	int		i;
	int		size;
	char	*str_dup;

	i = 0;
	size = finish - start + 1;
	str_dup = (char *)ft_calloc(1, sizeof(char) * (size + 1));
	if (!str_dup)
		return (NULL);
	while (start <= finish)
	{
		str_dup[i] = src[start];
		i++;
		start++;
	}
	return (str_dup);
}
