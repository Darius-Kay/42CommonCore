/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 06:31:11 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/19 16:08:01 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*strf;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = (unsigned int)ft_strlen(s);
	strf = (char *)ft_calloc(size + 1, sizeof(char));
	if (!strf)
		return (NULL);
	while (i < size)
	{
		strf[i] = (*f)(i, s[i]);
		i++;
	}
	return (strf);
}
