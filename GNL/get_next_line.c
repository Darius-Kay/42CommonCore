/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:41:08 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/27 14:23:19 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	s_len = ft_slen(s);
	if (len > s_len - start || len == 0)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i + start < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*ft_trimmer(char *str)
{
	int		i;
	char	*tmp_buf;

	i = 0;
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	tmp_buf = ft_substr(str, i + 1, -1);
	if (!tmp_buf)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (tmp_buf);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buf;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str) && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	buf = ft_substr(str, 0, ft_strchr(str));
	str = ft_trimmer(str);
	return (buf);
}
