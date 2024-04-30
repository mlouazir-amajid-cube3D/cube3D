/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:49:04 by mlouazir          #+#    #+#             */
/*   Updated: 2023/12/01 18:59:48 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void del(void* contet)
{
	free(contet);
	contet = NULL;
}
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
int main()
{
	t_list *h;
	t_list *n1;
	t_list *n2;
	t_list *n3;
	char *s = malloc(2);
	char *s1 = malloc(2);
	char *s2 = malloc(2);
	s[0] = '1';
	s1[0] = '2';
	s2[0] = '3';
	s[1] = '\0';
	s1[1] = '\0';
	s2[1] = '\0';

	n1 = ft_lstnew(s);
	h = n1;
	n2 = ft_lstnew(s1);
	n3 = ft_lstnew(s2);
	n1->next = n2;
	n2->next = n3;
	while (h)
	{
		printf("|%s|\n", h->content);
		h= h->next;
	}
	ft_lstdelone(n3,del);
	h = n1;
	// n2->next =NULL;
	while (h)
	{
		printf("|%s|\n", h->content);
		h= h->next;
	}
}