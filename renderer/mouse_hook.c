/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:31:02 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/13 18:48:37 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	mouse_in_motion(int x, int y, t_vars *v)
{
	(void)y;
	if (x - v->original_x > 0)
		v->mouse_movement = 1;
	else if (x - v->original_x < 0)
		v->mouse_movement = -1;
	v->original_x = x;
	renderer(v);
	return (0);
}
