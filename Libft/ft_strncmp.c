/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 06:59:41 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/15 22:10:31 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sb1;
	unsigned char	*sb2;

	sb1 = (unsigned char *)s1;
	sb2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (!sb1[i] || !sb2[i])
			return (sb1[i] - sb2[i]);
		if (sb1[i] != sb2[i])
			return (sb1[i] - sb2[i]);
		i++;
	}
	return (0);
}
