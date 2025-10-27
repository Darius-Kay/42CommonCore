/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 06:05:05 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/27 06:05:05 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_read(char *str, int fd)
{
	int end;

	end = read(fd, str, 40);
	str[end] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("test.c", O_RDONLY);
	str = malloc((sizeof (char)) * (40 + 1));
	while (i < atoi(av[1]))
	{
		str = ft_read(str, fd);
		printf("%s", str);
		i++;
	}
	free(str);
	return (0);
}
