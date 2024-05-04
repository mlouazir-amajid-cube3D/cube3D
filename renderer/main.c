#include <mlx.h>
#include <stdio.h>
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080

#define C 0xAA000000
#define F 0x0000AA00


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

} t_vars;

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
				my_mlx_pixel_put(data, j, i, F);
			else 
				my_mlx_pixel_put(data, j, i, C);
			j++;
		}
		i++;
	}
}



void draw_verline(t_data *data, int x, int start, int end, int color)
{

	while(start < end)
	{
		my_mlx_pixel_put(data, x, start, color);
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
	printf("Hello from key_hook!, %d\n", keycode);

	  //move forward if no wall in front of you
    if (keycode == 13)
    {
      if(worldMap[(int)(v->posX + v->dirX * v->moveSpeed)][(int)(v->posY)] == 0) v->posX += v->dirX * v->moveSpeed;
      if(worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->moveSpeed)] == 0) v->posY += v->dirY * v->moveSpeed;
    }
    //move backwards if no wall behind you
    if (keycode == 1)
    {
      if(worldMap[(int)(v->posX - v->dirX * v->moveSpeed)][(int)(v->posY)] == 0) v->posX -= v->dirX * v->moveSpeed;
      if(worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->moveSpeed)] == 0) v->posY -= v->dirY * v->moveSpeed;
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

		//which box of the map we're in
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
			if (worldMap[mapX][mapY] > 0) hit = 1;
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
		//choose wall color
		int color;
		{
			color = 0x00FF0000 * (worldMap[mapX][mapY] == 1) +  //red
			0x0000FF00 * (worldMap[mapX][mapY] == 2) +   //green
			0x000000FF * (worldMap[mapX][mapY] == 3) +  //blue
			0x00FFFFFF * (worldMap[mapX][mapY] == 4) +  //white
			0x00FFFF00 * (worldMap[mapX][mapY] == 0	);  //yellow
		}

		//give x and y sides different brightness
		if (side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		draw_verline(&v->img, x, drawStart, drawEnd, color);
		//timing for input and FPS counter
		v->time++;

		//speed modifiers
		v->moveSpeed = 1.0; //the constant value is in squares/second
		v->rotSpeed =  1.0; //the constant value is in radians/second
	}

	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img.img, 0, 0);
	return 0;
}


int main()
{

	t_vars v = {.posX = 22, .posY = 12,  //x and y start position
		.dirX = -1, .dirY = 0, //initial direction vector
		.planeX = 0, .planeY = 0.66, //the 2d raycaster version of camera plane
		.time = 0, //time of current frame
		.moveSpeed = 0, //the constant value is in squares/second
		.rotSpeed = 0, //the constant value is in radians/second
		.mlx = mlx_init(),
	};
	
	

	v.mlx_win = mlx_new_window(v.mlx, screenWidth, screenHeight, "cube3d"),
	mlx_key_hook(v.mlx_win, key_hook, &v);
	v.img.img = mlx_new_image(v.mlx, 1920, 1080);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, &v.img.line_length,
	&v.img.endian);
	renderer(&v);
	mlx_loop_hook(v.mlx, renderer, &v);
	mlx_loop(v.mlx);
}