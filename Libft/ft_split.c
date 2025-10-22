/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:21:14 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/21 20:32:52 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freesplit(char **split, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(split[i]);
		i++;
	}
	free (split);
}

static int	ft_cw(char *str, int c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == 0)
			break ;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static char	**ft_create_string(char **split, char const *s, char c)
{
	int	start;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			split[j] = ft_strdup_fstf((char *)s, start, i);
			if (!split[j++])
			{
				ft_freesplit(split, ft_cw((char *)s, c));
				return (NULL);
			}
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc(1, sizeof(char *) * (ft_cw((char *)s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_create_string(split, s, c);
	return (split);
}
