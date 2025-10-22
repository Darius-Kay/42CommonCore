/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:09:21 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/20 00:30:37 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)ft_calloc(1, sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	while (i < len_s1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		join[i] = s2[i - len_s1];
		i++;
	}
	return (join);
}
