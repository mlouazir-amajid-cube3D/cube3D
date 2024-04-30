/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:31:38 by mlouazir          #+#    #+#             */
/*   Updated: 2023/12/01 18:37:25 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	over(char *s, int i, int n)
{
	unsigned long	r;
	int				digits;

	digits = 0;
	r = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		if (digits >= 19 && n == 1)
			return (-1);
		if (digits >= 19 && n == -1)
			return (0);
		r = (r * 10) + (s[i] - 48);
		i++;
		digits++;
	}
	return (r * n);
}

int	ft_atoi(const char *s)
{
	int					n;
	int					i;

	n = 1;
	i = 0;
	while (((9 <= s[i] && s[i] <= 13) || s[i] == 32) && s[i])
		i++;
	if (s[i] == '-')
	{
		i++;
		n = -1;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	return (over((char *)s, i, n));
}
// #include "stdio.h"
// int main(int argc, char const *argv[])
// {
// 	char s[] = "-184467440737095551616";
// 	printf("%d\n", ft_atoi(s));
// 	printf("%d\n", atoi(s));
// 	return 0;
// }
