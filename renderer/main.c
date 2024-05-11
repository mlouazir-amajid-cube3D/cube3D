#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "../cub.h"

#define mapWidth 10
#define mapHeight 10
#define screenWidth 1920
#define screenHeight 1080

int	getcolor(t_vars *v, int x, int y)
{
	char *add;
	int	bp;
	int	sl;
	int	en;
	int res;

	add = mlx_get_data_addr(v->map->ea_tex, &bp, &sl, &en);
	res = *(unsigned int*)(add + (y * sl + x * (bp / 8)));
	return (res);
}

static inline void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void clear_img(t_data *data)
{
	int i = 0;
	while (i < screenHeight) {
		int j = 0;
		while (j < screenWidth) {
			if(i < (screenHeight/2))
				my_mlx_pixel_put(data, j, i, data->F);
			else 
				my_mlx_pixel_put(data, j, i, data->C);
			j++;
		}
		i++;
	}
}

void draw_verline(t_data *data, int x, int start, int end, int* color)
{
	int	i = 0;

	while(start < end)
	{
		my_mlx_pixel_put(data, x, start, color[i++]);
		start++;
	}
}

double abs_d(double x)
{
	if (x < 0.0F) {
		return x * -1.0F;
	}
	return x;
}

int	key_hook(int keycode, t_vars *v)
{
	  //move forward if no wall in front of you
    if (keycode == 13)
    {
      if(v->map->content[(int)(v->posY)][(int)(v->posX + v->dirX * v->moveSpeed)] == '0') v->posX += v->dirX * v->moveSpeed;
      if(v->map->content[(int)(v->posY + v->dirY * v->moveSpeed)][(int)(v->posX)] == '0') v->posY += v->dirY * v->moveSpeed;
    }
    //move backwards if no wall behind you
    if (keycode == 1)
    {
      if(v->map->content[(int)(v->posY)][(int)(v->posX - v->dirX * v->moveSpeed)] == '0') v->posX -= v->dirX * v->moveSpeed;
      if(v->map->content[(int)(v->posY - v->dirY * v->moveSpeed)][(int)(v->posX)] == '0') v->posY -= v->dirY * v->moveSpeed;
    }
	
	if (keycode == 2)
    {
		double right_x = v->dirY;
		double right_y = -v->dirX;
		if(v->map->content[(int)(v->posY)][(int)(v->posX + right_x * v->moveSpeed)] == '0') v->posX += right_x * v->moveSpeed;
		if(v->map->content[(int)(v->posY + right_y * v->moveSpeed)][(int)(v->posX)] == '0') v->posY += right_y * v->moveSpeed;
    }
	if (keycode == 0)
    {
		double right_x = v->dirY;
		double right_y = -v->dirX;
		if(v->map->content[(int)(v->posY)][(int)(v->posX - right_x * v->moveSpeed)] == '0') v->posX -= right_x * v->moveSpeed;
		if(v->map->content[(int)(v->posY - right_y * v->moveSpeed)][(int)(v->posX)] == '0') v->posY -= right_y * v->moveSpeed;
    }
	
    //rotate to the right
    if (keycode == 124)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = v->dirX;
      v->dirX = v->dirX * cos(-v->rotSpeed) - v->dirY * sin(-v->rotSpeed);
      v->dirY = oldDirX * sin(-v->rotSpeed) + v->dirY * cos(-v->rotSpeed);
      double oldPlaneX = v->planeX;
      v->planeX = v->planeX * cos(-v->rotSpeed) - v->planeY * sin(-v->rotSpeed);
      v->planeY = oldPlaneX * sin(-v->rotSpeed) + v->planeY * cos(-v->rotSpeed);
    }
    //rotate to the left
    if (keycode == 123)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = v->dirX;
      v->dirX = v->dirX * cos(v->rotSpeed) - v->dirY * sin(v->rotSpeed);
      v->dirY = oldDirX * sin(v->rotSpeed) + v->dirY * cos(v->rotSpeed);
      double oldPlaneX = v->planeX;
      v->planeX = v->planeX * cos(v->rotSpeed) - v->planeY * sin(v->rotSpeed);
      v->planeY = oldPlaneX * sin(v->rotSpeed) + v->planeY * cos(v->rotSpeed);
    }

	return (0);
}

int renderer(t_vars *v)
{
	int w = screenWidth;
	clear_img(&v->img);
	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = v->dirX + v->planeX * cameraX;
		double rayDirY = v->dirY + v->planeY * cameraX;
		
		//which box of the map we're i
		int mapX = (int)v->posX;
		int mapY = (int)v->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = abs_d(1.0 / rayDirX);
		double deltaDistY = abs_d(1.0 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (v->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - v->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (v->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - v->posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (v->map->content[mapY] != NULL && v->map->content[mapY][mapX] != 0 && v->map->content[mapY][mapX] > '0') hit = 1;
		} 

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);
		int h = screenHeight;
		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;

		double wallx;
		int		tex;

		if (!side)
			wallx = rayDirY  * perpWallDist + v->posY;
		else
			wallx = rayDirX  * perpWallDist + v->posX;

		wallx -= floor(wallx);

		tex = wallx * 64.f;

		if(side == 0 && rayDirX > 0) tex = 64 - tex - 1;
      	if(side == 1 && rayDirY < 0) tex = 64 - tex - 1;
		double steps;

		steps = 64 / lineHeight;

		double texPos = (drawStart - h / 2 + lineHeight / 2) * steps;

		int	*buf = malloc(sizeof(int) * (drawEnd - drawStart));
		int	index = 0;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (64 - 1);
			texPos += steps;
			buf[index] = getcolor(v, tex, texY);
			index++;
		}
		draw_verline(&v->img, x, drawStart, drawEnd, buf);
		free(buf);
		v->time++;

		v->moveSpeed = 0.4; //the constant value is in squares/second
		v->rotSpeed =  0.2; //the constant value is in radians/second
	}

	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img.img, 0, 0);
	return 0;
}


int renderer_init(t_map *map)
{
	printf("map->player_pos_x = %d, map->player_pos_y = %d\n", map->player_pos_x, map->player_pos_y);
	t_vars v = {//.posX = 1, .posY = 1,
		.posX = map->player_pos_x + .3f, .posY = map->player_pos_y + .3f,  //x and y start position
		.dirX = -1, .dirY = 0, //initial direction vector
		.planeX = 0, .planeY = 1.0f, //the 2d raycaster version of camera plane
		.time = 0, //time of current frame
		.moveSpeed = 0, //the constant value is in squares/second
		.rotSpeed = 0, //the constant value is in radians/second
		.mlx = mlx_init(),
		.map = map
	};
	
	mlx_do_key_autorepeaton(v.mlx);	
	v.mlx_win = mlx_new_window(v.mlx, screenWidth, screenHeight, "cube3d"),
	mlx_key_hook(v.mlx_win, key_hook, &v);
	v.img.img = mlx_new_image(v.mlx, 1920, 1080);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, &v.img.line_length,
	&v.img.endian);
	v.img.F = map->f_col;
	v.img.C = map->c_col;
	
	renderer(&v);
	mlx_loop_hook(v.mlx, renderer, &v);
	mlx_loop(v.mlx);
	return 0;
}
