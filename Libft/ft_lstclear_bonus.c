/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakaymak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:16:41 by dakaymak          #+#    #+#             */
/*   Updated: 2025/10/20 00:37:18 by dakaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	if (tmp == NULL)
		*lst = NULL;
	else
	{
		while (tmp)
		{
			tmp2 = tmp->next;
			del(tmp->content);
			free(tmp);
			tmp = tmp2;
		}
	}
	*lst = NULL;
}
