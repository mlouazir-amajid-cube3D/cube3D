/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:29:28 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/12 19:08:07 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	key_hook(int keycode, t_vars *v)
{
    if (keycode == 13)
    {
      if(v->map->content[(int)(v->pos_y)][(int)(v->pos_x + v->dir_x * v->move_speed)] == '0')
	  	v->pos_x += v->dir_x * v->move_speed;
      if(v->map->content[(int)(v->pos_y + v->dir_y * v->move_speed)][(int)(v->pos_x)] == '0')
	  	v->pos_y += v->dir_y * v->move_speed;
    }
    if (keycode == 1)
    {
      if(v->map->content[(int)(v->pos_y)][(int)(v->pos_x - v->dir_x * v->move_speed)] == '0')
	  	v->pos_x -= v->dir_x * v->move_speed;
      if(v->map->content[(int)(v->pos_y - v->dir_y * v->move_speed)][(int)(v->pos_x)] == '0')
	  	v->pos_y -= v->dir_y * v->move_speed;
    }
	if (keycode == 2)
    {
		double right_x = v->dir_y;
		double right_y = -v->dir_x;
		if(v->map->content[(int)(v->pos_y)][(int)(v->pos_x + right_x * v->move_speed)] == '0') v->pos_x += right_x * v->move_speed;
		if(v->map->content[(int)(v->pos_y + right_y * v->move_speed)][(int)(v->pos_x)] == '0') v->pos_y += right_y * v->move_speed;
    }
	if (keycode == 0)
    {
		double right_x = v->dir_y;
		double right_y = -v->dir_x;
		if(v->map->content[(int)(v->pos_y)][(int)(v->pos_x - right_x * v->move_speed)] == '0') v->pos_x -= right_x * v->move_speed;
		if(v->map->content[(int)(v->pos_y - right_y * v->move_speed)][(int)(v->pos_x)] == '0') v->pos_y -= right_y * v->move_speed;
    }
	
    //rotate to the right
    if (keycode == 124)
    {
      //both camera direction and camera plane must be rotated
      double olddir_x = v->dir_x;
      v->dir_x = v->dir_x * cos(-v->rot_speed) - v->dir_y * sin(-v->rot_speed);
      v->dir_y = olddir_x * sin(-v->rot_speed) + v->dir_y * cos(-v->rot_speed);
      double old_plane_x = v->plane_x;
      v->plane_x = v->plane_x * cos(-v->rot_speed) - v->plane_y * sin(-v->rot_speed);
      v->plane_y = old_plane_x * sin(-v->rot_speed) + v->plane_y * cos(-v->rot_speed);
    }
    //rotate to the left
    if (keycode == 123)
    {
      //both camera direction and camera plane must be rotated
      double olddir_x = v->dir_x;
      v->dir_x = v->dir_x * cos(v->rot_speed) - v->dir_y * sin(v->rot_speed);
      v->dir_y = olddir_x * sin(v->rot_speed) + v->dir_y * cos(v->rot_speed);
      double oldplane_x = v->plane_x;
      v->plane_x = v->plane_x * cos(v->rot_speed) - v->plane_y * sin(v->rot_speed);
      v->plane_y = oldplane_x * sin(v->rot_speed) + v->plane_y * cos(v->rot_speed);
    }

	return (0);
}