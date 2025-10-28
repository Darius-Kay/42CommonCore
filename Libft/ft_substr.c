/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:17:52 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/27 10:22:45 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	if (!s || len == 0 || start >= ft_strlen(s))
	{
		sub = (char *)ft_calloc(1, sizeof(char) * 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
