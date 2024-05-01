/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:27 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/01 15:29:02 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
#define CUB_3D

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "./utils/libft/libft.h"

typedef struct s_map
{
	char	**map;
	char	*filename;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		fd;
} t_map;

void	print_error(char *mssg);
int		map_name_check(char *filename);
char	*get_next_line(int fd);
void	save_map(t_map *info);

#endif