/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:17:54 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/26 04:35:34 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	lst[1024];
	char			*strline;

	if (!(lst[fd].line))
		lst[fd].line = 0;
	ft_lstadd(&lst[fd]);
	if (!(lst[fd].next))
		return (NULL);
	ft_readfd(&lst[fd], fd, (lst[fd].line));
	strline = ft_joincontent(&lst[fd]);
	if (!strline)
		return (NULL);
	return (strline);
}
