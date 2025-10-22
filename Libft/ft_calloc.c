/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 05:36:19 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/20 00:44:19 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	size_t	len;

	if (nmemb == 0 || size == 0)
	{
		buf = malloc(0);
		if (!buf)
			return (NULL);
		return (buf);
	}
	if (size != 0 && (nmemb > ((size_t) - 1) / size))
		return (NULL);
	len = nmemb * size;
	buf = malloc(len);
	if (!buf)
		return (NULL);
	ft_bzero(buf, len);
	return (buf);
}
