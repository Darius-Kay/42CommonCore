/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:17:54 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/26 05:57:02 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_lstinit(t_list *lst)
{
	if (!lst[0].line)
		lst[0].line = 0;
	lst[0].next = NULL;
}

char	*get_next_line(int fd)
{
	static content	lst[1024];
	char			*strline;

	if (BUFFER_SIZE == 0)
		return (NULL);
	if (!(lst[fd].line))
		ft_lstinit(&lst[fd]);
	ft_lstadd(&lst[fd]);
	if (!(lst[fd].next))
		return (NULL);
	ft_readfd(&lst[fd], fd, (lst[fd].line));
	strline = ft_joincontent(&lst[fd]);
	if (!strline)
		return (NULL);
	return (strline);
}
