/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:19:40 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/16 19:31:27 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (!*l)
		return (b);
	while (i < len && b[i])
	{
		j = 0;
		while (i + j < len && b[i + j] && b[i + j] == l[j])
		{
			j++;
			if (l[j] == '\0')
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
