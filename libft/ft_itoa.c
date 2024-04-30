/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:22:08 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/09 18:37:47 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_stockn(char *str, int n, int *p)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		ft_memset((str + *p), '-', 1);
		*p += 1;
	}
	if (ln > 9)
	{
		ft_stockn(str, ln / 10, p);
		ft_stockn(str, ln % 10, p);
	}
	else
	{
		ft_memset((str + *p), (ln + '0'), 1);
		*p += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		s;
	int		p;

	ln = n;
	p = 0;
	s = 0;
	if (ln < 0)
	{
		ln = -ln;
		s++;
	}
	while (ln >= 10)
	{
		ln /= 10;
		s++;
	}
	s++;
	str = malloc(s + 1);
	if (str == NULL)
		return (NULL);
	ft_stockn(str, n, &p);
	str[s] = '\0';
	return (str);
}
