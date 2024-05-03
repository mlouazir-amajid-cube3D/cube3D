/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:27 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 11:32:23 by mlouazir         ###   ########.fr       */
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

typedef struct s_info
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
} t_info;

typedef struct s_map
{
	char	**content;
	void	*no_tex;
	void	*so_tex;
	void	*we_tex;
	void	*ea_tex;
	int		f_col;
	int		c_col;
} t_map;

void	print_error(char *mssg);
int		map_name_check(char *filename);
char	*get_next_line(int fd);
t_map	*save_map(t_info *info);
void	verify_line(t_info *info, char *line);
void	clear_all(t_map *m, t_info *in, char *mssg, int status);
void	clear_array(char **array, int size);
void	generate_colors(int *dest, char *src);
void	map_content_check(t_map *map, t_info *info, char *line);
int		array_size(char **array);
#endif