/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:18:02 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/26 05:36:35 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd(t_list *lst)
{
	t_list	*tmp;
	t_list	*new_n;

	new_n = (t_list *)malloc(sizeof(t_list));
	if (!new_n)
		return ;
	new_n->next = NULL;
	tmp = lst;
	if (!lst)
		lst = new_n;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_n;
	}
}

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp = lst->next;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	lst->next = NULL;
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*tmp;

	if (!lst)
		return (0);
	size = 1;
	tmp = lst;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

//si ya haja c ici
char	*ft_joincontent(t_list *lst)
{
	int		i;
	char	*strj;
	size_t	lstsize;
	t_list	*tmp_list;

	tmp_list = lst->next;
	lstsize = ft_lstsize(tmp_list);
	strj = (char *)malloc(sizeof(char) * (lstsize * BUFFER_SIZE + 1));
	if (!strj)
		return (NULL);
	while (tmp_list)
	{
		strj[i] = tmp_list->content[i % BUFFER_SIZE];
		i++;
		if (i % BUFFER_SIZE == 0)
			tmp_list = tmp_list->next;
	}
	strj[i] = '\0';
	ft_lstfree(lst);
	return (strj);
}

void	ft_readfd(t_list *lst, int fd, int line_nbr)
{
	int		i;
	t_list	*tmp_list;
	char	c;

	i = 0;
	tmp_list = lst->next;
	while (line_nbr)
	{
		read(fd, &c, 1);
		if (c == '\n')
			line_nbr--;
	}
	while (0 < read(fd, &c, 1) && c != '\n')
	{
		(tmp_list)->content[i % BUFFER_SIZE] = c;
		i++;
		if (i % BUFFER_SIZE == 0)
		{
			ft_lstadd(lst);
			tmp_list = tmp_list->next;
		}
	}
	if (c == '\n')
		tmp_list->content[i % BUFFER_SIZE] = c;
	lst->line = lst->line + 1;
}
