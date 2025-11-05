/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:09:03 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/28 17:09:03 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	int 	fd2;
	char	*caca;

	(void)ac;
	(void)av;
	i = 0;
	fd = open("even", O_RDONLY);
	fd2 = open("odd", O_RDONLY);
	while (i < 4)
	{
		caca = get_next_line(fd);
		printf("%s", caca);
		free(caca);
		caca = get_next_line(fd2);
		printf("%s", caca);
		free(caca);
		i++;
	}
	close(fd);
	close(fd2);
	return (0);
}
