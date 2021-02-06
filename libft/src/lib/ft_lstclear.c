/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:10:12 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/22 11:43:40 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = *lst;
			del((*lst)->content);
			*lst = temp->next;
			free(temp);
		}
	}
	*lst = NULL;
}
