/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:25:40 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/18 14:40:57 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;
	int		i;

	str = (char *)s;
	res = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			res = &str[i];
			if ((unsigned char)c == 0 && *res == '\0')
				return (res);
		}
		i = i + 1;
	}
	if (str[i] == '\0' && (unsigned char)c == 0)
		res = &str[i];
	return (res);
}
