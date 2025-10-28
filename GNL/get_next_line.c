/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:41:08 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/28 06:11:36 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char *s)
{
	int		i;
	int		j;
	char	*sub;

	if (!s || !s[0])
		return (NULL);
	j = 0;
	i = ft_strchr(s);
	if (s[i] == '\n')
		i++;
	else if (i == 0 && s[0] != '\n')
		i = ft_slen(s);
	sub = (char *)malloc(sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	while (j < i)
	{
		sub[j] = s[j];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

//a refaire abb\naa
static char	*ft_trimmer(char *s)
{
	int		i;
	int		j;
	char	*tmp_buf;

	if (!s || !s[0])
	{
		free(s);
		return (NULL);
	}
	i = ft_strchr(s);
	j = 0;
	if (s[i] == '\n')
		i++;
	else if (i == 0 && s[0] != '\n')
		i = ft_slen(s);
	tmp_buf = (char *)malloc(sizeof(char) * (ft_slen(s) - i + 1));
	if (!tmp_buf)
		return (NULL);
	while (s[i])
	{
		tmp_buf[j] = s[i];
		i++;
		j++;
	}
	free(s);
	tmp_buf[j] = '\0';
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
	while (ft_strchr(str) == 0 && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	buf = ft_substr(str);
	str = ft_trimmer(str);
	return (buf);
}
