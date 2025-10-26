/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 05:28:09 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/26 05:35:23 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("main.c", O_RDONLY);
	while (i < 25)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
}
