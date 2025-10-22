/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:22:01 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/21 20:16:57 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (size == 0 && src && !dest)
		return (size_src);
	size_dest = ft_strlen(dest);
	i = 0;
	if (size == 0 || size <= size_dest)
		return (size + size_src);
	while (src[i] && size_dest + 1 < size)
		dest[size_dest++] = src[i++];
	dest[size_dest] = '\0';
	return (ft_strlen(dest) + size_src - i);
}
