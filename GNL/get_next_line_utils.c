/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:45:28 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/28 09:53:28 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(const char *s)
{
	size_t		i;
	char		*ptr;

	if (!s)
		return (0);
	ptr = (char *)s;
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		return (i);
	else
		return (0);
}

int	ft_slen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_joinedcpy(char *str, char *buf)
{
	int		i;
	int		j;
	char	*tmp_str;

	i = 0;
	j = 0;
	tmp_str = (char *)malloc(sizeof(char) * (ft_slen(str) + ft_slen(buf) + 1));
	if (!tmp_str)
		return (NULL);
	while (str && str[i])
	{
		tmp_str[i] = str[i];
		i++;
	}
	while (buf && buf[j])
	{
		tmp_str[i + j] = buf[j];
		j++;
	}
	tmp_str[i + j] = '\0';
	return (tmp_str);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*tmp_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	tmp_str = ft_joinedcpy(str, buf);
	ft_freeall(&str, NULL);
	return (tmp_str);
}
