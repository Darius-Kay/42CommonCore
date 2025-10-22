/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:35:51 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/17 03:20:34 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	char	*str;
	char	*str_d;

	i = 0;
	size_src = ft_strlen(src);
	str = (char *)src;
	str_d = (char *)dest;
	if (size > 0)
	{
		while (str[i] && i < size - 1)
		{
			str_d[i] = str[i];
			i++;
		}
		str_d[i] = '\0';
	}
	return (size_src);
}
