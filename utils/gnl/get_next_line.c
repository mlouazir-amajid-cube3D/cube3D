/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:36:21 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 21:35:33 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*ft_set_holder(char *holder)
{
	char	*newholder;
	int		hl;
	int		l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	hl = ft_strlen(holder);
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	l = hl - i;
	newholder = (char *)malloc(l + 1);
	if (!newholder)
	{
		free(holder);
		return (NULL);
	}
	while (j < l)
		newholder[j++] = holder[i++];
	newholder[j] = '\0';
	free(holder);
	return (newholder);
}

char	*ft_set_line(char *holder)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
	{
		free(holder);
		return (NULL);
	}
	while (j < i)
	{
		res[j] = holder[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_read(char *holder, int fd)
{
	char	reader[50 + 1];
	int		counter;

	holder = malloc(1);
	holder[0] = 0;
	while (!ft_strchr(holder, '\n'))
	{
		counter = read(fd, reader, 50);
		if (counter <= 0)
			break ;
		reader[counter] = '\0';
		holder = ft_strjoin(holder, reader);
	}
	if (holder == NULL)
		return (NULL); 
	if (read(fd, NULL, 0) == -1 || holder[0] == '\0')
	{
		free(holder);
		holder = NULL;
		return (NULL);
	}
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*res;

	if (fd < 0 || read(fd, 0, 0) == -1)
	{
		if (holder)
		{
			free(holder);
			holder = NULL;
		}
		return (NULL);
	}
	holder = ft_read(holder, fd);
	if (!holder)
		return (NULL);
	res = ft_set_line(holder);
	if (!res)
		return (NULL);
	holder = ft_set_holder(holder);
	if (!holder)
		return (NULL);
	return (res);
}