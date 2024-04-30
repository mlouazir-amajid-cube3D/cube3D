/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:41 by mlouazir          #+#    #+#             */
/*   Updated: 2023/12/01 18:37:31 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count * size >= LONG_MAX)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
// int main(int argc, char const *argv[])
// {
// 	char *s = ft_calloc(-1, 1);
// 	printf("%p", s);
// 	return 0;
// }
