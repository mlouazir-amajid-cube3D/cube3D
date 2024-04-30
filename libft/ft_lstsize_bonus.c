/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:28:31 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/12 16:55:04 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*ptr;

	if (!lst)
		return (0);
	c = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr -> next;
		c++;
	}
	return (c);
}
