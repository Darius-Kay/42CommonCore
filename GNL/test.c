/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 06:05:05 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/27 13:43:59 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("1char.txt", O_RDONLY);
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
		free(str);
	}
	return (0);
}
