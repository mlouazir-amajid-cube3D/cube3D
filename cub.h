/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:27 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/15 17:58:38 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "./utils/libft/libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_render
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_distance;
	int		side;
	int		line_height;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		draw_start;
	int		draw_end;
	int		x;
}	t_render;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		f;
	int		c;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*mlx_win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	unsigned int	time;
	double			move_speed;
	double			rot_speed;
	int				mouse_movement;
	int				original_x;
	struct s_map	*map;
	t_data			img;
}	t_vars;

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *v);
double	abs_d(double x);
int		re_init(t_map *map);
void	clear_img(t_data *data);
void	put_texture(t_vars *v, t_render *tool);
void	set_vector(t_map *map, t_vars *v);
int		renderer(t_vars *v);
int		win_destroyed(t_vars *v);
void	destroy(t_vars *v);

#endif