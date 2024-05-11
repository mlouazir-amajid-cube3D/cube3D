/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:27 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/11 18:31:46 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "./utils/libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int F;
	int C;
}				t_data;


typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data img;

	double posX, posY;  //x and y start position
	double dirX, dirY; //initial direction vector
	double planeX, planeY; //the 2d raycaster version of camera plane
	unsigned int time; //time of current frame
	//speed modifiers
	double moveSpeed; //the constant value is in squares/second
	double rotSpeed; //the constant value is in radians/second
	struct s_map *map;
} t_vars;

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
}	t_info;

typedef struct s_map
{
	char	**content;
	void	*no_tex;
	void	*so_tex;
	void	*we_tex;
	void	*ea_tex;
	void	*init;
	int		f_col;
	int		c_col;
	int		size;
	int		player_pos_x;
	int		player_pos_y;
	char	orientation;
}	t_map;

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
int		is_map_char(char c, int pass);
int		empty_space_check(t_map *map);
void	texture_file_check(t_map *map, t_info *info);
void	mlx_inti(t_map *map);
int renderer_init(t_map *map);
static inline void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif