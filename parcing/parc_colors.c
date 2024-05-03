/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:25:31 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 14:26:59 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	commas_count(char *src)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (src[++i])
		if (src[i] == ',')
			c++;
	return (c);
}

int	is_alldigit(char **array)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	tmp = NULL;
	while (array[++i])
	{
		j = 0;
		free(tmp);
		tmp = ft_strtrim(array[i], " \t");
		(!tmp) && (clear_all(NULL, NULL, "faille in malloc", 1), 0);
		while (tmp[j] && ft_isdigit(tmp[j]))
			j++;
		if ((tmp[j] && !ft_isdigit(tmp[j])) || j > 3)
			return (free(tmp), 1);
	}
	return (free(tmp), 0);
}

void	generate_colors(int *dest, char *src)
{
	char	**tmp;
	int		i;
	int		red;
	int		green;
	int		blue;

	i = -1;
	red = 0;
	green = 0;
	blue = 0;
	tmp = ft_split(src, ',');
	(!tmp) && (clear_all(NULL, NULL, "faille in malloc", 1), 0);
	while (tmp[++i])
		;
	((commas_count(src) != 2 || i != 3) || is_alldigit(tmp)) \
	&& (clear_array(tmp, -1), \
	clear_all(NULL, NULL, "Invalid Color", 1), 0);
	red = ft_atoi(tmp[0]);
	green = ft_atoi(tmp[1]);
	blue = ft_atoi(tmp[2]);
	clear_array(tmp, -1);
	(!(0 <= red && red <= 255) || !(0 <= blue && blue <= 255) \
	|| !(0 <= green && green <= 255)) \
	&& (clear_all(NULL, NULL, "Invalid Color", 1), 0);
	*dest = (red << 16) | (green << 8) | (blue);
}
