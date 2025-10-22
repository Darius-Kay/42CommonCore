/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 01:39:30 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/21 21:01:52 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy_s1;
	size_t	start;
	size_t	finish;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	finish = ft_strlen(s1) - 1;
	while (ft_is_charset(s1[start], set))
		start++;
	while (finish > start && ft_is_charset(s1[finish], set))
		finish--;
	if (start == finish && ft_is_charset(s1[start], set))
		cpy_s1 = (char *)ft_calloc(1, sizeof(char));
	else
		cpy_s1 = ft_strdup_fstf((char *)s1, start, finish);
	if (!cpy_s1)
		return (NULL);
	return (cpy_s1);
}
