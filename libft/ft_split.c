/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:34:23 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/09 19:11:18 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countlength(char *s, char c)
{
	int	i;
	int	nws;

	i = 0;
	nws = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			nws++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nws);
}

static int	ft_eachlength(char *s, char c, int	*p)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[*p] && s[*p] == c)
		*p += 1;
	while (s[*p])
	{
		if (s[*p] == c)
			break ;
		else
		{
			l++;
			*p += 1;
		}
	}
	return (l);
}

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static	int	ft_allocat(char **str, char *s, int nwss, char c)
{
	int		eachlength;
	int		p;
	int		i;

	i = 0;
	p = 0;
	while (nwss != 0 && i < nwss)
	{
		eachlength = ft_eachlength((char *)s, c, &p);
		str[i] = ft_substr(s, (p - eachlength), eachlength);
		if (str[i] == NULL)
		{
			ft_free(str, i - 1);
			return (0); 
		}
		i++;
	}
	str[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nwss;
	int		r;

	if (s == NULL)
		return (NULL);
	nwss = ft_countlength((char *)s, c);
	str = malloc((nwss + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	r = ft_allocat(str, (char *)s, nwss, c);
	if (r == 0)
		return (NULL);
	return (str);
}
