/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:56:03 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/21 20:28:04 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*node_tmp;
	void	*data;

	new_l = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		data = f(lst->content);
		node_tmp = ft_lstnew(data);
		if (!node_tmp || !data)
		{
			del(data);
			if (node_tmp)
				free(node_tmp);
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, node_tmp);
		lst = lst->next;
	}
	return (new_l);
}
