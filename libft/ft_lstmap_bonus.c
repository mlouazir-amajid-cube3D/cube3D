/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:42 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/09 10:27:45 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	head = NULL;
	while (tmp != NULL)
	{
		n = ft_lstnew(NULL);
		if (n == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		n->content = f(tmp->content);
		ft_lstadd_back(&head, n);
		tmp = tmp->next;
	}
	return (head);
}
