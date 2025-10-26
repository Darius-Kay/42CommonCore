/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:13:28 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/26 04:34:47 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	size_t			line;
	struct s_list	*next;
}	t_list;

void	ft_lstadd(t_list *lst);
void	ft_lstfree(t_list *lst);
size_t	ft_lstsize(t_list *lst);
char	*ft_joincontent(t_list *lst);
void	ft_readfd(t_list *lst, int fd, int line_nbr);

#endif
