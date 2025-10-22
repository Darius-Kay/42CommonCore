/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 04:27:38 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/15 07:13:50 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*ptrone;
	unsigned char	*ptrtwo;

	ptrone = (unsigned char *)s1;
	ptrtwo = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ptrone[i] != ptrtwo[i])
			return (ptrone[i] - ptrtwo[i]);
		i++;
	}
	return (0);
}
